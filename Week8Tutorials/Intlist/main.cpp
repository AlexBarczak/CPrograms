#include <iostream>
#include "intlist.h"
using namespace std;


int main()
{
  Intlist int_list;
  int object;

  cout << "Enter list of integers, 0 to finish: " << endl << endl;
  cin >> object;
  while (object > 0)
  {
    int_list.Insert_At_End(object);
    cin >> object;
  }

  cout << endl << "List: " << int_list << endl;
  int_list.Double_Elements();
  cout << endl << "double the List: " << int_list << endl;
  cout << endl << "first element: " << int_list.Peek() << endl;
  cout << endl << "number of '3's in the list: " << int_list.Count_Occurences(3) << endl;
  cout << endl << "5th element in list: " << int_list.Element_At_P(5) << endl;


  while (!int_list.Empty())
  {
    cout << "Enter number to delete:  ";
    cin >> object;
    int_list.Delete(object);
    cout << "List: " << int_list << endl;
  }
  return 0;
}

