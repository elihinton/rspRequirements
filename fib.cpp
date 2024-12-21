#include <iostream>

using namespace std;

unsigned long int fib(int n, int* m){
    if (m[n] != NULL){
        return m[n];
    } else {
        if (n == 0){
            return 0;
        } else if(n == 1){
            return 1;
        } else {
            unsigned long int result = fib(n-1,m) + fib(n-2,m);
            m[n] = result;
            return result;
        }
    }
}

int main(void){

    int n;
    cout << "What fibonacci number do you want?: ";
    cin >> n;

    int* memoization = new int[n+1];
    for (int i = 0; i < n+1; i++){
        memoization[i] = NULL;
    }
    cout << fib(n,memoization) << endl;
    cout << fib(8,memoization) << endl;
    cout << fib(20,memoization) << endl;
    cout << fib(38,memoization) << endl; // overflow when too big as unsigned long int only goes to ~4.2 billion

    return 0;
}