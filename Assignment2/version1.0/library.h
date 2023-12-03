#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>

#include "user.h"
#include "book.h"
#include "film.h"
#include "audio.h"

using namespace std;

#define INVENTORY_FILE "./../inventory.txt"
#define USER_FILE "./../users.txt"

class library
{
private:
    vector<user*> users;
    vector<book*> books;
    vector<film*> films;
    vector<audio*> audios;
    // don't want these called seperately in case order is done incorrectly
    void loadItems();
    void loadUsers();
public:
    library();
    ~library();
    void addBook(book* book);
    void addFilm(book* book);
    void addAudio(book* book);
    void addUser(user* user);

    book* getBook(string& ISBN);
    film* getFilm(book* book);
    audio* getAudio(book* book);
    user* getUser(int& id);

    vector<book*>& getBooks();
    vector<film*>& getFilms();
    vector<audio*>& getAudios();
    vector<user*>& getUsers();

    void saveBooks();
    void saveUsers();
    void loadLibrary();

    vector<book*>& searchByTitle(vector<book*>& vectorToPopulate, string searchString);
};

#endif