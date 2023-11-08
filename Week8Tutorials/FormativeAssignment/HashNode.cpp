#include<iostream>
#include "HashNode.h"

HashNode::HashNode(){
    this->key = "";
    this->value = "";
}

HashNode::HashNode(string k, string v){
    this->key = k;
    this->value = v;
}

string HashNode::getKey() {
    return this->key;
}

void HashNode::setValue(string v){
    this->value = v;
}

string HashNode::getValue() {
    return this->value;
}

ostream& operator<<(ostream &output, const HashNode &hn) {
    output << hn.key << ':' << hn.value;
    return output;
}
