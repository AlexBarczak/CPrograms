#include <iostream>
#include <string>

#include "audio.h"

using namespace std;

audio::audio(string title, string author, int availability, string id)
    : item(title, author, availability){
    this->id = id;
}

string audio::getID(){
    return this->id;
}

void audio::setID(string id){
    this->id = id;
}

ostream& operator<<(ostream &os, audio *audio){
    os << audio->id << " \"" << audio->title << "\" \"" << audio->author << "\" ";
    os << to_string(audio->availability);
    return os;
}