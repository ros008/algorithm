#include <iostream>

using namespace std;


void printArr(int arr[], int len) {
    for(int i=0; i<len; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quickSort(int arr[], int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (i <= end && arr[i] <= arr[pivot])
            i++;
        while (j > start && arr[j] >= arr[pivot])
            j--;
        if(i > j) {
            swap(arr, j, pivot);
        } else {
            swap(arr, i, j);
        }
    }

    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}

int main() {
    int arr[10] = { 4, 9, 1, 6, 11, 10, 3, 15, 2, 13 };
    int len = 10;

    quickSort(arr, 0, len - 1);

    printArr(arr, len);

    return 0;
}