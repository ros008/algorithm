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

void selectionSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        swap(arr, min, i);
    }
}

int main()
{
    int arr[10] = {4, 9, 1, 6, 11, 10, 3, 15, 2, 13};
    int len = 10;

    selectionSort(arr, len);

    printArr(arr, len);

    return 0;
}