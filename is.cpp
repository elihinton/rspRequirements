#include <iostream>

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int array[], int n){
    for (int i = 1; i < n; i++){
        int j = i;
        while (j > 0 && array[j] < array[j-1]){
            swap(array[j], array[j-1]);
            j--;
        }
    }
}

int main(void){

    int arry[] = {1,4,5,8,2,9,3,6,7};
    int size = sizeof(arry) / sizeof(arry[0]);

    insertionSort(arry,size);
    for (auto number : arry){
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}