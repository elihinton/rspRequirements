#include <vector>
#include <iostream>

using namespace std;

int main(void){

    vector<int> num(10,0);

    for (int& i : num){
        i += 2;
        cout << i << " ";
    }
    cout << endl;

    return 0;
}