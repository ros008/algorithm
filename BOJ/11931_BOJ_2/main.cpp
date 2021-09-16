#include <iostream>

#define MAX 1000000

using namespace std;

int N;
int arr[MAX + 1];
int tmpArr[MAX + 1];

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int i = start, j = mid + 1, k = start;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            tmpArr[k++] = arr[i++];
        else
            tmpArr[k++] = arr[j++];
    }

    while (i <= mid)
        tmpArr[k++] = arr[i++];
    while (j <= end)
        tmpArr[k++] = arr[j++];

    for (int i = start; i <= end; i++)
        arr[i] = tmpArr[i];
}

void merge_sort(int start, int end)
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
        int input;
        cin >> input;
        arr[i] = input;
    }
    merge_sort(0, N - 1);
    for (int i = N - 1; i >= 0; i--)
        cout << arr[i] << "\n";
    return 0;
}