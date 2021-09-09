#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
bool flag;

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort()
{
    for (int i = N - 1; i > 0; i--)
    {
        flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}

void selection_sort()
{
    int min = 0, tmp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[min] > arr[j])
                min = j;
        }
        if (i != min)
        {
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

void insertion_sort()
{
    int cur, j;
    for (int i = 1; i < N; i++)
    {
        cur = arr[i];
        j = i - 1;
        while (cur < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
}

void merge(int start, int end)
{
}

void merge_sort(int start, end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, end);
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    insertion_sort();

    for (int i = 0; i < N; i++)
        cout << arr[i] << "\n";

    return 0;
}