#ifndef AUDIO_H
#define AUDIO_H

#include <string>

#include "item.h"

using namespace std;

class audio : public item
{
private:
    string id;
public:
    string getID();
    void setID(string id);
    audio(string title, string author, int availability, string id);
    friend ostream& operator<<(ostream &stream, audio *book);
};

#endif