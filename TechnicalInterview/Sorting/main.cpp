#include <iostream>

using namespace std;

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// quick sort
void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j)
    {
        while (i <= end && arr[i] <= arr[pivot])
            i++;
        while (j > start && arr[j] >= arr[pivot])
            j--;
        if (i > j)
            swap(arr, j, pivot);
        else
            swap(arr, i, j);
    }
    quickSort(arr, start, j - 1);
    quickSort(arr, j + 1, end);
}

// heap sort
void heapify(int arr[], int len, int root)
{
    int left = root * 2 + 1;
    int right = root * 2 + 2;
    int max = root;

    if (left < len && arr[left] > arr[max])
        max = left;
    if (right < len && arr[right] > arr[max])
        max = right;

    if (max != root)
    {
        swap(arr, max, root);
        heapify(arr, len, max);
    }
}

void heapSort(int arr[], int len)
{
    for (int i = len / 2; i >= 0; i--)
    {
        heapify(arr, len, i);
    }

    int arrLen = len;
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        arrLen--;
        heapify(arr, arrLen, 0);
    }
}

// merge sort
void merge(int arr[], int start, int end)
{
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int tmp[10];
    int p = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            tmp[p++] = arr[i++];
        else
            tmp[p++] = arr[j++];
    }

    while (i <= mid)
    {
        tmp[p++] = arr[i++];
    }
    while (j <= end)
    {
        tmp[p++] = arr[j++];
    }

    for (int i = 0; i < p; i++)
    {
        arr[start + i] = tmp[i];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end);
    }
}

// insertion sort
void insertionSort(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int cur = arr[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > cur)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = cur;
    }
}

// bubble sort
void bubbleSort(int arr[], int len)
{
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                swap(arr, j, j + 1);
            }
        }
    }
}

// selection sort
void selectionSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        swap(arr, min, i);
    }
}

int main()
{
    int arr[10] = {4, 9, 1, 6, 11, 10, 3, 15, 2, 13};
    int len = 10;

    insertionSort(arr, len);

    printArr(arr, len);

    return 0;
}