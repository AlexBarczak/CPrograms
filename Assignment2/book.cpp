#include <iostream>
#include <string>

#include "book.h"

using namespace std;

book::book(string title, string author, string ISBN, int availability){
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    this->availability = availability;
}

string book::getTitle(){
    return this->title;
}

void book::setTitle(string title){
    this->title = title;
}

string book::getAuthor(){
    return this->author;
}

void book::setAuthor(string author){
    this->author = author;
}

string book::getISBN(){
    return this->ISBN;
}

void book::setISBN(string ISBN){
    this->ISBN = ISBN;
}

int book::getAvailability(){
    return this->availability;
}

void book::setAvailablity(int availability){
    this->availability = availability;
}

ostream& operator<<(ostream &os, book *book){
    os << book->ISBN << " \t" << book->title << " \t" << book->author << " \t";
    os << to_string(book->availability);
    return os;
}