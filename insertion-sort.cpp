#include <iostream>

// O(n^2) runtime complexity
// great when already partially sorted

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int* array, int size){
    for (int i = 1; i < size; i++){
        int j = i;
        while (j > 0 && array[j] < array[j - 1]){
            swap(array[j],array[j-1]);
            j--;
        }
    }
}

int main(void){

    int array[] = {1,322,2,5,4};
    int n = 5;

    insertionSort(array,n);

    for (int i = 0; i < n; i++){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}