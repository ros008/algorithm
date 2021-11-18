#include <iostream>

using namespace std;

void printArr (int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void merge (int arr[], int start, int end) {
    int mid = (start + end) / 2;
    int i = start; 
    int j = mid + 1;
    int tmp[8];
    int p = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            tmp[p++] = arr[i++];
        } else {
            tmp[p++] = arr[j++];
        }
    }

    while (i <= mid) {
        tmp[p++] = arr[i++];
    }

    while (j <= end) {
        tmp[p++] = arr[j++];
    }

    for(int i = 0; i < p; i++) {
        arr[start + i] = tmp[i];
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

int main() {
    int arr[8] = {6,5,3,1,8,7,2,4};
    int len = 8;

    mergeSort(arr, 0, len - 1);

    printArr(arr, len);

    return 0;
}