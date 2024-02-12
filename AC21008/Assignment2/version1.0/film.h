#ifndef FILM_H
#define FILM_H

#include <string>

#include "item.h"

using namespace std;

class film : public item
{
private:
    string id;
public:
    string getID();
    void setID(string id);
    film(string title, string author, int availability, string id);
    friend ostream& operator<<(ostream &stream, film *book);
};

#endif