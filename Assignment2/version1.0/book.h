#ifndef BOOK_H
#define BOOK_H

#include <string>

#include "item.h"

using namespace std;

class book : public item
{
private:
    string ISBN;
public:
    book(string title, string author, int availability, string ISBN);
    string getISBN();
    void setISBN(string ISBN);
    friend ostream& operator<<(ostream &stream, book *book);
};

#endif