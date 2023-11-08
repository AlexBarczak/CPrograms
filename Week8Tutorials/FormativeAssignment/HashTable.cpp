#include <iostream>
#include <algorithm>
#include <cmath>

#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
    tablesize = 10;
    table = new HashNode[10];
}

HashTable::HashTable(int size) {
    tablesize = size;
    table = new HashNode[size];
}

HashTable::~HashTable() {
    delete [] table;
}

int HashTable::hashFunction(string k){
    int prime = 13;
    int hash_index = 0;

    for (int index = 0; index < max(3, (int)k.length()); index++)
    {
        hash_index += ((int)k[index]*pow(prime, index - 1));
    }

    hash_index %= 11;

    return hash_index;
}

bool HashTable::insert(string k, string v){
    int first_index = hashFunction(k);

    if (this->table[first_index].getKey() == ""){
        this->table[first_index] = HashNode(k, v);
        return true;
    }else if(this->table[first_index].getKey() == k){return false;}
    for (int offset = 0; offset < this->tablesize; offset++)
    {
        if (this->table[(first_index + offset)%tablesize].getKey() == ""){
            this->table[(first_index + offset)%tablesize] = HashNode(k, v);
            return true;
        }else if (this->table[first_index].getKey() == k){
            return false;
        }
    }
    return false;
}

int HashTable::search(string k){
    int first_index = hashFunction(k);

    if (this->table[first_index].getKey() == k){
        return first_index;
    }else 
    if(this->table[first_index].getKey() == ""){
        return -1;
    }

    for (int offset = 0; offset < this->tablesize; offset++)
    {
        if (this->table[(first_index + offset)%tablesize].getKey() == k){
            return (first_index + offset)%tablesize;
        }else if (this->table[first_index].getKey() == ""){
            return -1;
        }
    }
    return -1;
}

bool HashTable::update(string k, string v){
    int index = search(k);

    if (index == -1){
        return false;
    }

    this->table[index].setValue(v);
    return true;    
}

string HashTable::lookup(string k){
    int index = search(k);

    if (index == -1){
        return "";
    }

    return this->table[index].getValue();
}

ostream& operator<<(ostream &output, const HashTable &ht) {
    for (int index = 0; index < ht.tablesize; index++)
    {
        output << index << ':' << ht.table[index] << endl;
    }
    return output;
}
