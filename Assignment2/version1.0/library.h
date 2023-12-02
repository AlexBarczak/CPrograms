#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

#include "user.h"
#include "book.h"

using namespace std;

#define INVENTORY_FILE "./../inventory.txt"
#define USER_FILE "./../users.txt"

class library
{
private:
    vector<user*> users;
    vector<book*> books;
    // don't want these called seperately in case order is done incorrectly
    void loadBooks();
    void loadUsers();
public:
    library();
    ~library();
    void addBook(book* book);
    void addUser(user* user);
    book* getBook(string& ISBN);
    user* getUser(int& id);
    vector<book*>& getBooks();
    vector<user*>& getUsers();
    void saveBooks();
    void saveUsers();
    void loadLibrary();
    vector<book*>& searchByTitle(vector<book*>& vectorToPopulate, string searchString);
};

#endif