#include "intlist.h"

// Constructor
Intlist :: Intlist() : Head(nullptr)
{
}

// Destructor

Intlist :: ~Intlist()
{
  Node* temp;
  while (Head != nullptr)
  {
    temp = Head;
    Head = Head -> Next;
    delete temp;
  }
}

// Tests

bool Intlist :: Empty() const
{
  return (Head == nullptr) ? true : false;
}

// Insert (simple insert at beginning)

bool Intlist :: Insert(const int& new_element)
{
  Node* new_node;
  new_node = new Node;
  new_node -> Element = new_element;
  new_node -> Next = Head;
  Head = new_node;
  return true;
}

// Delete

bool Intlist :: Delete(const int& del_element)
{
  Node* temp;
  Node* previous;

  if (Empty()) 
    return false;
  else if (Head -> Element == del_element)
  {
    temp = Head;
    Head = Head -> Next;
    delete temp;
    return true;
  }
  else if (Head -> Next == nullptr)
    return false;
  else 
  {
    previous = Head;
    temp = Head -> Next;
    while ((temp -> Element != del_element) &&
           (temp -> Next != nullptr))
    {
      previous = temp;
      temp = temp -> Next;
    }
    if (temp -> Element == del_element)
    {
      previous -> Next = temp -> Next;
      delete temp;
      return true;
    }
    else  // list exhausted
      return false;
  }
}

// Print

void Intlist :: Print(ostream& out_stream) const
{
  Node* temp;
  temp = Head;
  while (temp != nullptr)
  {
    out_stream << temp -> Element << " ";
    temp = temp -> Next;
  }
}

// Overloaded output operator
  
ostream& operator<<(ostream& out_stream,
                    const Intlist& out_list)
{
  out_list.Print(out_stream);
  return out_stream;
}

int Intlist :: Peek(){
  return this->Head->Element;
}

void Intlist :: Double_Elements(){
  Node* current_node = this->Head;
  while (current_node != nullptr)
  {
    current_node->Element *= 2;
    current_node = current_node->Next;
  }
}

int Intlist :: Length(){
  int count = 0;
  Node* current_node = this->Head;

  while (current_node != nullptr)
  {
    count++;
    current_node = current_node->Next;
  }

  return count;
}

int Intlist :: Element_At_P(int pos){
  Node* current_node = this->Head;
  
  for (int index = 0; index < pos; index++)
  {
    current_node = current_node->Next;
  }

  return current_node->Element;
}

int Intlist :: Count_Occurences(int value){
  int count = 0;
  Node* current_node = this->Head;
  
  while (current_node != nullptr)
  {
    if(current_node->Element == value){count++;}
    current_node = current_node->Next;
  }

  return count;
}

bool Intlist :: Insert_At_End(const int& new_element){
  Node* current_node = this->Head;
  Node* new_node = new Node(new_element, nullptr);

  if (current_node == nullptr)
  {
    this->Head = new_node;
    return true;
  }
  while (current_node->Next != nullptr)
  {
    current_node = current_node->Next;
  }
  current_node->Next = new_node;
  
  return true;
}