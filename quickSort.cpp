#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

void quickSort(int array[], int length);

void quickSortRecursion(int array[], int low, int high);

int partition(int array[], int low, int high);\

int main(void){

    int a[] = {10,21,2,1,43,21,22,23,4,9,8,2,7,5,3};
    int length = sizeof(a) / sizeof(a[0]);

    quickSort(a,length);

    for (int i = 0; i < length; i++){
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

void quickSort(int array[], int length){
    quickSortRecursion(array,0,length-1);
}

void quickSortRecursion(int array[], int low, int high){
    int pivotIndex = partition(array,low,high);

    quickSortRecursion(array,low,pivotIndex-1);          
    quickSortRecursion(array,pivotIndex+1,high);          
}   

int partition(int array[], int low, int high){

}