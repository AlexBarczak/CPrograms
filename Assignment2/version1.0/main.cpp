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

void browseInventory(){
    vector<book*> foundBooks;
    string searchString;

    cout << "please enter a search string, or enter nothing if you wish to see all items" << endl;
    
    cin.ignore();
    getline(cin, searchString);

    foundBooks = lib->searchByTitle(foundBooks, searchString);

    cout << "here are our items displayed in the format" << endl
        << "ISBN " << "\t\t\tTitle " << "\t\t\tAuthor " << "\t\tAmount in stock" << endl;
    
    auto current = foundBooks.begin();
    auto end = foundBooks.end();

    while (current != end)
    {
        cout << *current << endl;
        current = next(current);
    }
}

void userSignIn(){
    // if current user is defined, skip function
    if (currentUser != nullptr){return;}

    cout << endl 
        << "Welcome to the library\n"
        << "What would you like to do:\n"
        << "1. show all user data\n"
        << "2. browse inventory\n"
        << "3. sign in with your user ID\n"
        << "4. open an account with the library\n"
        << "5. add a book\n"
        << "6. remove a book\n"
        << "7. quit the program" << endl;

    string action;
    cin >> action;

    // show all users and borrowed out book ISBNs
    if (action == "1")
    {
        auto current = lib->getUsers().begin();
        auto end = lib->getUsers().end();

        while (current != end)
        {
            cout << *current << endl;
            current = next(current);
        }
    }
    // browse available books
    else if (action == "2")
        browseInventory();
    // sign in with your user id
    else if (action == "3")
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
    }
    // open an account with the library
    else if (action == "4")
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
    }
    // add a book
    else if (action == "5")
    {
        string ISBN;
        string Title;
        string Author;

        cout << "what is the ISBN of the book?\n";
        cin >> ISBN;

        book* pbook;
        bool bookExists = true;

        try
        {
            pbook = lib->getBook(ISBN);
        }
        catch(const std::exception& e)
        {
            bookExists = false;
        }

        if (bookExists)
        {
            cout << "this item is already recorded in the library\n"
                << "do you wish to donate another copy?" << endl;
            
            if (getYesOrNo() == 'y')
            {
                pbook->setAvailablity(pbook->getAvailability()+1);
                cout << "a copy of " << pbook->getTitle() << " has been added" << endl;
            }
        }
        
        cout << "what is the book's title?";
        getline(cin, Title);

        cout << "who is the book's Author?";
        getline(cin, Author);

        pbook = new book(Title, Author, ISBN, 1);
    }
    // remove a book
    else if (action == "6")
    {
        cout << "enter the ISBN of the item you want to remove:" << endl;
        string ISBN;
        cin >> ISBN;

        // check the book ISBN is valid
        book* pbook;

        try
        {
            pbook = lib->getBook(ISBN);
        }
        catch(const std::exception& e)
        {
            cout << "no such ISBN in our library";
            return;
        }

        // if the book is borrowed out by anyone, we cannot delete it
        auto currentUserIt = lib->getUsers().begin();
        auto endUserIt = lib->getUsers().end();

        while (currentUserIt != endUserIt)
        {
            if ((*currentUserIt)->hasBorrowed(pbook))
            {
                cout << "cannot remove a book while it is borrowed out\n"
                    << pbook->getISBN() << " is borrowed out by " << (*currentUserIt)->getUserName() << endl;
                return;
            }
        }

        // erase the book from the vector
        auto currentBook = lib->getBooks().begin();
        auto endBook = lib->getBooks().end();

        while (currentBook != endBook)
        {
            if (*currentBook == pbook)
            {
                lib->getBooks().erase(currentBook);
                delete pbook;
                lib->saveBooks();
                return;
            }
            currentBook = next(currentBook);
        }
    }
    // quit the program
    else if (action == "7")
    {
        exit(EXIT_SUCCESS);
    }
}

void mainMenu(){

    // if we don;t yet know the user, skip this
    if (currentUser == nullptr)
    {
        return;
    }
    
    cout << "Greetings, " << currentUser->getUserName() << " what would you like to do?\n"; 

    cout << "1. browse or search through the items\n"
            << "2. borrow a book out\n"
            << "3. return a book\n"
            << "4. log out\n"
            << "5. delete account" << endl;

    string input;
    cin >> input;

    if (input.length() != 1)
    {
        cout << "input not recognised" << endl;
        return;
    }
    
    switch (input[0])
    {
    // display books
    case '1':
    {
        browseInventory();
    }
        break;
    // borrow a book    
    case '2':
    {
        cout << "enter the ISBN of the item you want to take out:" << endl;
        string ISBN;
        cin >> ISBN;

        try
        {
            currentUser->borrowBook(lib->getBook(ISBN));
            lib->saveBooks();
            lib->saveUsers();
        }
        catch(const std::exception& e)
        {
            cout << e.what() << '\n'; 
        }
    }
        break;
    // return a book
    case '3':
        {
        cout << "enter the ISBN of the item you want to return:" << endl;
        string ISBN;
        cin >> ISBN;

        try
        {
            currentUser->returnBook(lib->getBook(ISBN));
            lib->saveBooks();
            lib->saveUsers();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        }
        break;
    // log out
    case '4':
        currentUser = nullptr;
        return;
        break;
    //delete this user
    case '5':
        // if user has borrowed out books ask them to return them before deleting their account
    {
        if (currentUser->getBorrowedBooks().begin() != currentUser->getBorrowedBooks().end())
        {
            cout << "You still have unreturned books, please return them before deleting your account" << endl;
            break;
        }

        auto current = lib->getUsers().begin();
        auto end = lib->getUsers().end();

        while(current != end){
            if (*current == currentUser)
            {
                lib->getUsers().erase(current);
                delete currentUser;
                currentUser = nullptr;
                lib->saveUsers();
                cout << "Youe account has been successfully deleted" << endl;
                return;
            }
            current = next(current);
        }
    }
        break;
    default:
        cout << "input not recognised" << endl;
        break;
    }
}

int main(int argc, char const *argv[]){

    currentUser = nullptr;

    lib = new library();
    lib->loadLibrary();

    // in an infinite loop to allow signing out of one
    // user account and into another one
    while (true)
    {
        userSignIn();
        mainMenu();
    }
}