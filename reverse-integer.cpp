#include <iostream>

using namespace std;

int reverse(int num){
    int rev = 0;
    while (num != 0){
        int rem = num % 10;
        rev = rev*10 + rem;
        num /= 10;
    }
    return rev;
}

int main(void){

    int number = 123456;
    int reversedNumber = reverse(number);
    cout << reversedNumber << endl;

    return 0;
}
