#ifndef INTLIST
#define INTLIST
#include <iostream>
using namespace std;

// Basic list for integers, minimal functionality

class Intlist
{
private:
  class Node
  {
  public:
    int Element;
    Node* Next;
    
    Node() : Next(nullptr) {}
    Node(int data, Node* pnode = nullptr) :
      Element(data), Next(pnode) {}
  };

  Node* Head;
public:
  Intlist();
  ~Intlist();
  bool Empty() const;
  bool Insert(const int& new_element);
  bool Insert_At_End(const int& new_element);
  bool Delete(const int& del_element);
  void Print(ostream& out_stream) const;
  int Peek();
  void Double_Elements();
  int Length();
  int Element_At_P(int pos);
  int Count_Occurences(int value);
};

ostream& operator<<(ostream& out_stream,
                    const Intlist& out_list);
#endif
