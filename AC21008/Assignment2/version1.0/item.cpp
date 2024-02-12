#include <string>

#include "item.h"

using namespace std;

item::item(string title, string author, int availability)
{
    this->title = title;
    this->author = author;
    this->availability = availability;
}

string item::getTitle(){
    return this->title;
}

void item::setTitle(string title){
    this->title = title;
}

string item::getAuthor(){
    return this->author;
}

void item::setAuthor(string author){
    this->author = author;
}

int item::getAvailability(){
    return this->availability;
}

void item::setAvailablity(int availability){
    this->availability = availability;
}