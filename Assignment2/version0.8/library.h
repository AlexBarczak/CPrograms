#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

#include "user.h"
#include "book.h"

using namespace std;

class library
{
private:
    vector<user*> users;
    vector<book*> books;
public:
    library();
    ~library();
    void addBook(book* book);
    void addUser(user* user);
    book* getBook(string& ISBN);
    user* getUser(int& id);
    vector<book*>& getBooks();
    vector<user*>& getUsers();
};

#endif