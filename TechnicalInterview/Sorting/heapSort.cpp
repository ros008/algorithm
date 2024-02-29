#include <iostream>

using namespace std;

void printArr (int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void swap(int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void heapify(int arr[], int len, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max = i;

    if (left < len && arr[left] > arr[max]) {
        max = left;
    }

    if (right < len && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr, max, i);
        cout << max << "\n";
        printArr(arr, len);
        heapify(arr, len, max);
    }
}

void heapSort(int arr[], int len) {
    for (int i = len / 2; i >= 0; i--) {
        heapify(arr, len, i);
    }

    printArr(arr, len);

    int arrLen = len;
    for(int i = len - 1; i > 0; i--) {
        swap(arr, 0, i);
        arrLen--;
        heapify(arr, arrLen, 0);
    }
}

int main() {
    int arr[10] = {5, 6, 10, 4, 3, 8, 7, 1, 2, 9};
    int size = 10;

    heapSort(arr, size);

    printArr(arr, size);

    return 0;
}