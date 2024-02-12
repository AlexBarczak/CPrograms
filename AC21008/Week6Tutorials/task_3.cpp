/*
    task 3 includes a number of exercising testing knowledge and understanding of
    input and output streams, getting inputs, displaying outputs and utilising
    functions
*/

#include <iostream>
#include <limits>
#include <string>
#include <stdlib.h>
using namespace std;

void print_stars(int n){
    string stars(n, '*');
    cout << stars;
}

void print_chars(int n, char c){
    string chars(n, c);
    cout << chars;
}

void print_rect(int width, int height){
    for (int i = 0; i < height; i++){
        print_stars(width);
        cout << endl;
    }
}

void print_diamond(int max_width){
    int start_width = (max_width % 2) + 1;

    for (int i = start_width; i <= max_width; i += start_width){
        int whitespaces = (max_width - i)/2;
        print_chars(whitespaces, ' ');
        print_stars(i);
        print_chars(whitespaces, ' ');
        cout << endl;
    }
    for (int i = max_width; i >= start_width; i -= start_width){
        int whitespaces = (max_width - i)/2;
        print_chars(whitespaces, ' ');
        print_stars(i);
        print_chars(whitespaces, ' ');
        cout << endl;
    }
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

int main(){
    while(true){
        char input;

        system("clear");

        cout << "what do you want to do?" << endl;
        cout << "1. draw a rectangle" << endl;
        cout << "2. draw a diamond" << endl;
        cout << "3. leave" << endl;

        cin >> input;

        switch (input){
            case '1':
                int width; 
                int height;

                cout << "rectangle" << endl;
                cout << "width: " << endl;
                width = get_int();
                cout << "height: " << endl;
                height = get_int();
                print_rect(width, height);
                cout << "type something in to return" << endl;
                cin >> input;
                break;
            case '2':
                cout << "diamond" << endl;
                cout << "how wide do you want it?" << endl;
                print_diamond(get_int()); 
                cout << "type something in to return" << endl;
                cin >> input;
                break;
            case '3':
                return 0;
            default:
                cout << "input unrecognised" << endl;
                break;
        }
    }
    return 0;
}