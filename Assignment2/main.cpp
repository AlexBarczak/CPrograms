#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

#include "library.h"
#include "book.h"
#include "user.h"

using namespace std;

user* currentUser;
library* lib;

void loadBooks(){
    string line;
    ifstream inventoryFile ("inventory.txt");
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
            lib->addBook(pbook);
        }
        inventoryFile.close();
    }
}

void loadUsers(){
    string line;
    ifstream userFile ("users.txt");
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
                        borrowedBooks.push_back(lib->getBook(ISBN));
                        break;
                    }

                    ISBN = line.substr(start, end-start);
                    borrowedBooks.push_back(lib->getBook(ISBN));

                    start = end + 1;
                    end = line.find_first_of(' ', start);
                }
            }
            
            puser = new user(id, name, borrowedBooks);
            lib->addUser(puser);
        }
        userFile.close();
    }
}

void saveUsers(){
    string line;
    ofstream userFile ("users.txt");

}

void saveBooks(){
    string line;
    ofstream inventoryFile ("inventory.txt");

    auto current = lib->getBooks().begin();
    auto end = lib->getBooks().end();

    
}

char getYesOrNo(){
    while (true)
    {
        char ch;
        string input;

        cin >> input;
        ch = input[0];
        ch = tolower(ch);

        if (ch == 'y' || ch == 'n')
        {
            return ch;
        }
        cout << "enter 'Y' OR 'N'" << endl;
    }
}

string getName(){
    string name;

    // this can completely destroy the read function for users if someone
    // puts a whitespace into their name
    cout << "To set up a profile for you, we'll need to know your name:" << endl;
    while (true)
    {
        char ch;

        cin.ignore();
        getline(cin, name);

        // remove whitespaces to keep file safe from breaking the read operation
        auto newNameEnd = remove(name.begin(), name.end(), ' ');
        name.erase(newNameEnd, name.end());
        cout << name << " then, is that right? (Y/N)" << endl;

        ch = getYesOrNo();
        
        if (ch == 'n')
        {
            return getName();
        }
        return name;
    }
}

void userSignIn(){
    // if current user not defined, get the user
    if (currentUser == nullptr)
    {

        cout << endl 
            << "Welcome to the library" << endl
            << "What would you like to do: " << endl
            << "1. sign in with your user ID" << endl
            << "2. open an account with the library" << endl
            << "3. quit the program" << endl;

        string action;
        cin >> action;

        if (action == "1")
        {
            while (true)
            {
                cout << "enter your user ID" << endl;
                cout << "or enter '-1' to cancel the action" << endl;
                string input;
                user* puser;

                cin >> input;
                if (input == "-1")
                {
                    userSignIn();
                    return;
                }
                
                try
                {
                    int id = stoi(input);
                    puser = lib->getUser(id);
                }
                catch(const std::out_of_range& e)
                {
                    cout << "your id is out of the possible range of values" << endl << endl;
                    continue;
                }
                catch(const std::invalid_argument& e)
                {
                    string error = e.what();
                    if (error == "stoi")
                    {
                        cout << "that is not a valid number id" << endl;
                    }else{
                        cout << error << endl;
                    }
                    cout << endl;
                    continue;
                }
                catch(const std::exception& e)
                {
                    cout << "something went wrong: " << e.what() << endl << endl;
                    continue;
                }
                currentUser = puser;
                return;
            }
            
        }else if (action == "2")
        {
            // sign up
            // ask the user for their name and assign them an ID

            int userID;
            string name;
            vector<book*> books;

            // as the user details are read in top to bottom and are stored in order of userid
            // we can ensure that we can generate a unique id so long as it is one plus the largest 
            // id among the ones on the file
            // as vector pushes each user to the end of the structure as it loads each in
            // the end of the vector hold the user with the largest user id
            userID = (lib->getUsers().back())->getUserID() + 1;
            name = getName();

            user* newUser = new user(userID, name, books);
            lib->addUser(newUser);
            currentUser = newUser;

            ofstream userFile;
            userFile.open("users.txt", ios_base::app);
            userFile << newUser << endl; 
            userFile.close();

            cout << "Welcome " << name << " you are now registered under userID: " << userID << endl;
            cout << "and are now signed in" << endl << endl;
        }else if (action == "3")
        {
            exit(EXIT_SUCCESS);
        }
    }
}

void mainMenu(){

    while (true)
    {
        cout << "Greetings, " << currentUser->getUserName() << " what would you like to do?\n"; 

        cout << "1. browse the items\n"
             << "2. borrow a book out\n"
             << "3. return a book\n"
             << "4. log out\n"
             << "5. delete account" << endl;

        string input;
        cin >> input;

        if (input.empty())
        {
            continue;
        }
        
        switch (input[0])
        {
        case '1':
            {
            cout << "here are our items displayed in the format" << endl
                << "ISBN " << "\t\t\tTitle " << "\t\t\tAuthor " << "\t\tAmount in stock" << endl;
            
            auto current = lib->getBooks().begin();
            auto end = lib->getBooks().end();

            while (current != end)
            {
                cout << *current << endl;
                current = next(current);
            }
            }
            break;
        case '2':
            {
            cout << "enter the ISBN of the item you want to take out:" << endl;
            string ISBN;
            cin >> ISBN;

            try
            {
                currentUser->borrowBook(lib->getBook(ISBN));
            }
            catch(const std::exception& e)
            {
                cout << e.what() << '\n'; 
            }
            }
            break;
        case '3':
            cout << "enter the ISBN of the item you want to return:" << endl;
            /* code */
            break;
        case '4':
            /* code */
            break;
        case '5':
            /* code */
            break;
        default:
            cout << "input not recognised" << endl;
            break;
        }
    }
}

int main(int argc, char const *argv[]){

    currentUser = nullptr;
    lib = new library();

    loadBooks();
    loadUsers();

    auto current = lib->getUsers().begin();
    auto end = lib->getUsers().end();

    while (current != end)
    {
        cout << *current << endl;
        current = next(current);
    }

    // in an infinite loop to allow signing out of one
    // user account and into another one
    while (true)
    {
        userSignIn();
        mainMenu();
    }
}