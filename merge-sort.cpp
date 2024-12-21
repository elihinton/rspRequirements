#include <iostream>

void merge(int* array, int s, int e) {
    int mid = (s + e) / 2;

    int i = s;        // Start of left half
    int j = mid + 1;  // Start of right half
    int k = 0;        // Start of temporary array

    int* temp = new int[e - s + 1];  // Temporary array to hold the merged result

    // Merge two halves
    while (i <= mid && j <= e) {
        if (array[i] < array[j]) {
            temp[k++] = array[i++];
        } else {
            temp[k++] = array[j++];
        }
    }

    // If there are remaining elements in the left half
    while (i <= mid) {
        temp[k++] = array[i++];
    }

    // If there are remaining elements in the right half
    while (j <= e) {
        temp[k++] = array[j++];
    }

    // Copy the merged elements back to the original array
    for (int i = 0; i < e - s + 1; i++) {
        array[s + i] = temp[i];  // Copy starting from index s
    }

    // Clean up the dynamically allocated memory
    delete[] temp;
}

void mergeSort(int array[], int s, int e) {
    if (s >= e) {
        return;
    }
    int mid = (s + e) / 2;
    mergeSort(array, s, mid);  // Sort left half
    mergeSort(array, mid + 1, e);  // Sort right half

    merge(array, s, e);  // Merge the two halves
}

int main(void) {
    int array[] = {9, 7, 8, 6, 2, 3, 1, 4, 5, 0, -1, -2, 12, 14, 13, 22, 21};
    int n = sizeof(array) / sizeof(array[0]);

    mergeSort(array, 0, n - 1);

    // Print the sorted array
    for (const auto number : array) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
