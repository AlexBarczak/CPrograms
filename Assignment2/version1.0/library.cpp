#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "library.h"
#include "user.h"
#include "book.h"

using namespace std;

library::library(){

}

library::~library(){
    auto currentb = this->books.begin();
    auto endb = this->books.end();

    while (currentb != endb)
    {
        book* pbook = *currentb;
        currentb = next(currentb);
        delete pbook;
    }
    
}

void library::addBook(book* book){
    this->books.push_back(book);
}

void library::addUser(user* user){
    this->users.push_back(user);
}

book* library::getBook(string& ISBN){
    auto current = this->books.begin();
    auto end = this->books.end();

    while (current != end)
    {
        if ((*current)->getISBN() == ISBN)
        {
            return *current;
        }
        current = next(current);
    }
    throw std::invalid_argument("No book with that ISBN");  
}

user* library::getUser(int& id){
    auto current = this->users.begin();
    auto end = this->users.end();

    while (current != end)
    {
        if ((*current)->getUserID() == id)
        {
            return *current;
        }
        current = next(current);
    }
    throw std::invalid_argument("No user with that ID");  
}

// returning references so as to not have the vector be copied each time this is called
vector<book*>& library::getBooks(){
    return this->books;
}

vector<user*>& library::getUsers(){
    return this->users;
}

void library::loadBooks(){
    string line;
    ifstream inventoryFile (INVENTORY_FILE);
    if (inventoryFile.is_open())
    {
        while (getline(inventoryFile, line))
        {
            book* pbook;
            string ISBN;
            string title;
            string author;
            int availability;

            int start = 0;
            int end = line.find_first_of(' ');
            ISBN = line.substr(start, end - start);

            // set start of substring to position after whitespace and '"'
            start = end + 2;
            end = line.find_first_of('"', start);
            title = line.substr(start, end - start);

            // same as above but this time the starting position is one before the whitespace also
            start = end + 3;
            end = line.find_first_of('"', start);
            author = line.substr(start, end-start);

            start = end + 2;
            end = line.find_first_of('\n', start);
            availability = stoi(line.substr(start, end-start));

            pbook = new book(title, author, ISBN, availability);
            this->addBook(pbook);
        }
        inventoryFile.close();
    }
}

void library::loadUsers(){
    string line;
    ifstream userFile (USER_FILE);
    if (userFile.is_open())
    {
        while (getline(userFile, line))
        {
            user* puser;
            
            int id;
            string name;
            vector<book*> borrowedBooks;

            // fetch the id
            int start = 0;
            int end = line.find_first_of(' ');  
            id = stoi(line.substr(start, end-start));

            // fetch the name
            start = end + 1;
            end = line.find_first_of(' ', start);

            // if end returns string::npos, we have reached the strings end
            // and there is nothing after the next substring
            if (end == string::npos) {
                name = line.substr(start);
            } 
            // otherwise we still need to process the ISBN identifiers
            // for borrowed out books
            else {
                name = line.substr(start, end-start);

                start = end + 1;
                end = line.find_first_of(' ', start);

                while (true){
                    string ISBN;

                    if (end == string::npos)
                    {
                        ISBN = line.substr(start);
                        borrowedBooks.push_back(this->getBook(ISBN));
                        break;
                    }

                    ISBN = line.substr(start, end-start);
                    borrowedBooks.push_back(this->getBook(ISBN));

                    start = end + 1;
                    end = line.find_first_of(' ', start);
                }
            }
            
            puser = new user(id, name, borrowedBooks);
            this->addUser(puser);
        }
        userFile.close();
    }
}

void library::saveBooks(){
    string line;
    ofstream inventoryFile (INVENTORY_FILE);

    auto current = this->getBooks().begin();
    auto end = this->getBooks().end();

    while (current != end)
    {
        inventoryFile << (*current) << endl;
        current = next(current);
    }

    inventoryFile.close();
}

void library::saveUsers(){
    string line;
    ofstream userFile (USER_FILE);

    auto current = this->getUsers().begin();
    auto end = this->getUsers().end();

    while (current != end)
    {
        userFile << (*current) << endl;
        current = next(current);
    }

    userFile.close();
}

// items need to be loaded first
void library::loadLibrary(){
    loadBooks();
    loadUsers();
}

vector<book*>& library::searchByTitle(vector<book*>& vectorToPopulate, string searchString){
    // iterate over all elements in the library and if the search string is
    // within the title, add the entry to the items to be returned

    auto current = this->books.begin();
    auto end = this->books.end();

    while (current != end)
    {
        if ((*current)->getTitle().find(searchString) != string::npos)
        {
            vectorToPopulate.push_back(*current);
        }
        current = next(current);
    }
    
    return vectorToPopulate;
}