#include <iostream>

void merge(int array[], int s, int e){
    int mid = (s+e)/2;

    int i = s;
    int j = mid + 1;
    int k = 0;

    int* temp = new int[e-s+1];

    while (i <= mid && j <= e){
        if (array[i] < array[j]){
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }
    while (j <= e){
        temp[k++] = array[j++];
    }
    while (i <= mid){
        temp[k++] = array[i++];
    }
    for (int i = 0; i < e-s+1; i++){
        array[s+i] = temp[i];
    }
    delete[] temp;
}

void mergeSort(int array[], int s, int e){
    if (s >= e){
        return;
    }
    int mid = (s+e)/2;

    mergeSort(array,s,mid);
    mergeSort(array,mid+1,e);

    merge(array,s,e);
}

int main(void){
    int array[] = {9,1,8,2,3,7,4,7,5,6};
    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array,0,size-1);

    for (int number : array){
        std::cout << number << " ";
    }
    std::cout << std::endl;
}