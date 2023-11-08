#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include "Complex.h"
using namespace std;

bool test1() {
    double r=2, i=6;
    Complex c1(r,i);
    if (c1.get_real() != r) {
        cout << "Real part not correctly set in constructor" << endl;
        return false;
    }
    if (c1.get_img() != i) {
        cout << "Imaginary part not correctly set in constructor" << endl;
        return false;
    }
    return true;
}

bool test2() {
    double r1=2, i1=3, r2=2, i2=-6;
    Complex c1(r1,i1);
    Complex c2(r2,i2);
    Complex c3;
    c3 = c1 + c2;
    if (c3.get_real() != r1+r2) {
        cout << "Incorrect sum for real parts" << endl;
        return false;
    }
    if (c3.get_img() != i1+i2) {
        cout << "Incorrect sum for imaginary parts" << endl;
        return false;
    }
    return true;
}

bool test3(double r, double i, string target) {
    Complex c1(r,i);
    stringstream buffer;
    streambuf * old = cout.rdbuf(buffer.rdbuf());
    cout << c1;
    string test = buffer.str();
    cout.rdbuf(old);
    test.erase(remove(test.begin(), test.end(), '\n'), test.end());
    test.erase(remove(test.begin(), test.end(), ' '), test.end());
    if (test != target){
        cout << "Output is incorrect for " << target << " you said " << test <<  endl;
        return false;
    }
    return true;
}

int main() {
    if (!test1()) {
        cout << "Test 1: FAILED" << endl;
        return 1;
    }else{
        cout << "Test 1: PASSED" << endl;
    }
    if (!test2()) {
        cout << "Test 2: FAILED" << endl;
        return 1;
    }else{
        cout << "Test 2: PASSED" << endl;
    }
    if (!test3(3.4, 2.3, "3.4+2.3i")) {
        cout << "Test 3: FAILED" << endl;
        return 1;
    }else{
        cout << "Test 3: PASSED" << endl;
    }
	if (!test3(4.3, -2.1, "4.3-2.1i")) {
        cout << "Test 4: FAILED" << endl;
        return 1;
    }else{
        cout << "Test 4: PASSED" << endl;
    }
    if (!test3(0, -1, "0-i")) {
        cout << "Test 5: FAILED" << endl;
        return 1;
    }else{
        cout << "Test 5: PASSED" << endl;
    }
    return 0;
}
