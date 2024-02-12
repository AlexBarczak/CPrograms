#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <iostream>

#include "user.h"
#include "book.h"

using namespace std;

user::user(int &userID, string &name, vector<book*> &borrowedBooks){
    this->userID = userID;
    this->name = name;
    this->borrowedBooks = borrowedBooks;
}

int user::getUserID(){
    return this->userID;
}

string user::getUserName(){
    return this->name;
}

vector<book*> user::getBorrowedBooks(){
    return this->borrowedBooks;
}

void user::setUserName(string &name){
    this->name = name;
}

bool user::hasBorrowed(book* book){
    auto current = this->borrowedBooks.begin();
    auto end = this->borrowedBooks.end();

    while (current != end)
    {
        if (*current == book)
        {
            return true;
        }
        current = next(current);
    }
    return false;    
}

void user::borrowBook(book* book){
    if (book->getAvailability() == 0)
    {
        throw std::invalid_argument("book is not available");
    }
    this->borrowedBooks.push_back(book);
    book->setAvailablity(book->getAvailability()-1);
}

void user::returnBook(book* book){
    auto current = this->borrowedBooks.begin();
    auto end = this->borrowedBooks.end();

    while (current != end)
    {
        if (*current == book)
        {
            (*current)->setAvailablity((*current)->getAvailability()+1);
            this->borrowedBooks.erase(current);
            return;
        }
        current = next(current);
    }
    throw std::invalid_argument("book is not borrowed by the user");
}

ostream& operator<<(ostream &outputStream, user* user){
    outputStream << user->userID << " " <<  user->name;
    auto current = user->borrowedBooks.begin();
    auto end = user->borrowedBooks.end();

    while (current != end)
    {
        outputStream << " " << (*current)->getISBN();
        current = next(current);
    }
    return outputStream;
}