#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class book
{
private:
    string title;
    string author;
    string ISBN;
    int availability;
public:
    book(string title, string author, string ISBN, int availability);
    string getTitle();
    void setTitle(string title);
    string getAuthor();
    void setAuthor(string author);
    string getISBN();
    void setISBN(string ISBN);
    int getAvailability();
    void setAvailablity(int availability);
    friend ostream& operator<<(ostream &stream, book *book);
};

#endif