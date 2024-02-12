/*
    task 4 consists of have the program ask the user to enter a number n and 
    calculate the nth triangular number using a recursive function call to
    calculate the result
*/

#include <iostream>
#include <limits>

using namespace std;

/* 
    return the objects that can form an equilateral triangle, the nth triangle number is
    the number of dots composing a triangle with n dots on a side, and is equal to the sum
    of natural numbers 1 to n
*/

int rec_get_triangular_number(int n){
    if(n == 1){
        return 1;
    }
    return n + rec_get_triangular_number(n-1);
}

int get_triangular_number(int n){
    if(n < 1){
        cout << "invalid input" << endl;
        return 0;
    }
    if (n == 1){
        return n;
    }
    return n + rec_get_triangular_number(n-1);
}

int get_int(){
    int num;
    cin >> num;
    while(cin.fail()){
        cout << "value unrecognised" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> num;
    }
    return num;
}

int main (){
    int number;

    cout << "enter a number n, to calculate the nth triangular number" << endl;
    number = get_int();
    cout << get_triangular_number(number) << endl;
    return 0;
}