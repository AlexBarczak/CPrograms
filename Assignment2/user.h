#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>

#include "book.h"

using namespace std;

class user
{
private:
    int userID;
    string name;
    vector<book*> borrowedBooks;
public:
    user(int &userID, string &name, vector<book*> &borrowedBooks);
    ~user();
    int getUserID();
    string getUserName();
    void setUserName(string& name);
    bool hasBorrowed(book* book);
    void borrowBook(book* book);
    void returnBook(book* book);
    friend ostream& operator<<(ostream &os, user* user);
};

#endif