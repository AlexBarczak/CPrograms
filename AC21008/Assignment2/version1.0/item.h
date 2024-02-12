#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class item
{
// protected instead of private to preserve my sanity
// and not have to call getters in subclasses
protected:
    string title;
    string author;
    int availability;
public:
    item(string title, string author, int availability);

    string getTitle();
    void setTitle(string title);
    string getAuthor();
    
    void setAuthor(string author);
    int getAvailability();
    void setAvailablity(int availability);
};

#endif