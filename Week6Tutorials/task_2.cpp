/*
    task 2 is just a basic manipulation of a pre-made function to change its operation
*/

#include <iostream>
using namespace std;

int max(int x, int y){
    if(x>y){
        return x;
    }
    return y;
}

int main(){
    int a,b;
    cout << "enter two numbers" << endl << "number 1:" << endl;
    cin >> a;
    cout << "number 2:" << endl;
    cin >> b;
    cout << "max of " << a << " and " << b << " is " << max(a,b) << endl; 
    return 0;
}