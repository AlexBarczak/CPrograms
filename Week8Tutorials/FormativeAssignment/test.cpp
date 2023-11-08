#include <iostream>
#include <string>
#include "HashTable.h"
using namespace std;

int main() {
	string names[8] = {"Alice", "Bob", "Chris", "Denise", "Ellen", "Fred", "George", "Hannah"};
	string exts[8] = {"123", "234", "345", "456", "567", "678", "789", "890"};

	HashTable abook(12);

	for(int i=0; i<8; i++){
		abook.insert(names[i], exts[i]);
    }

    cout << abook << endl;

    string sname = "Alice";
    cout << sname << " has ext " <<  abook.lookup("Alice") << endl;
	abook.update(sname, "987");
	cout << sname << " has ext " <<  abook.lookup("Alice") << endl;

	return 0;
}