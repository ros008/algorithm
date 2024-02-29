#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분 탐색
void binary_search(int *arr, int start, int end, int target)
{
    int mid;
    while (end >= start)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            cout << "1\n";
            return;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "0\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int arr[100001];

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr + N);

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        binary_search(arr, 0, N - 1, num);
    }

    return 0;
}