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

void insertionSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int cur = arr[i], j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > cur)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = cur;
    }
}

int main()
{
    int arr[10] = {4, 9, 1, 6, 11, 10, 3, 15, 2, 13};
    int len = sizeof(arr) / sizeof(int);

    insertionSort(arr, len);

    printArr(arr, len);

    return 0;
}