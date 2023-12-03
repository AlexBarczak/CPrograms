#include <iostream>
#include <string>

#include "book.h"

using namespace std;

book::book(string title, string author, int availability, string ISBN)
    : item(title, author, availability){
    this->ISBN = ISBN;
}

string book::getISBN(){
    return this->ISBN;
}

void book::setISBN(string ISBN){
    this->ISBN = ISBN;
}

ostream& operator<<(ostream &os, book *book){
    os << book->ISBN << " \"" << book->title << "\" \"" << book->author << "\" ";
    os << to_string(book->availability);
    return os;
}