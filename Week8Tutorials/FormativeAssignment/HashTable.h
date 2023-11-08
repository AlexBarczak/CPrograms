#ifndef HASHTABLE
#define HASHTABLE
#include "HashNode.h"
#include<string>
using namespace std;

class HashTable {
    private:
        int tablesize;
        HashNode* table;
    public:
        HashTable();
        HashTable(int size);
        ~HashTable();

        int hashFunction(string k);
        bool insert(string k, string v);
        int search(string k);
        bool update(string k, string v);
        string lookup(string k);

        friend std::ostream& operator<<(std::ostream &output, const HashTable &ht);
};
#endif
