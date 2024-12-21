#include <iostream>

using namespace std;

int main(void){

    int a = 15; // 00001111
    int b = 8;  // 00001000
    int c = 0;  // 00000000

    c = a << 1;
    cout << c << endl; // 00011110 // 30
    // left operator doubles size

    c = a >> 1;
    cout << c << endl; // 00000111 // 7
    // right operator halves size
    // if number is odd then and right operator is used then result will truncate

    c = a & b;
    cout << c << endl; // 00001000 // 8
    // A and B (AND) - both have bits 

    c = a | b;
    cout << c << endl; // 00001111 // 15
    // A or B (OR) - either have bits, both can have bits as well

    c = a ^ b;
    cout << c << endl; // 00000111 // 7 
    // exclusive A or B (XOR) - either have bits, but both cannot have bits

    c = ~ c;
    cout << c << endl;

    return 0;
}

//C++14 allows you to directly write binary into integer types via '0b...'