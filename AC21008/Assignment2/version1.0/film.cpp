#include <iostream>
#include <string>

#include "film.h"

using namespace std;

film::film(string title, string author, int availability, string id)
    : item(title, author, availability){
    this->id = id;
}

string film::getID(){
    return this->id;
}

void film::setID(string id){
    this->id = id;
}

ostream& operator<<(ostream &os, film *film){
    os << film->id << " \"" << film->title << "\" \"" << film->author << "\" ";
    os << to_string(film->availability);
    return os;
}