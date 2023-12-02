#include <string>
#include <vector>
#include <stdexcept>

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