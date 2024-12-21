#include <iostream>

using namespace std;

int main(void){

    int** dp = new int*[4];

    for (int i = 0; i < 4; i++){
        int arr[3] = {1,2,3};
        dp[i] = arr;
    }

    for (int row = 0; row < 4; row++){
        for (int col = 0; col < 3; col++){
            cout << dp[row][col] << " ";
        }
        cout << endl;
    }

    return 0;
}