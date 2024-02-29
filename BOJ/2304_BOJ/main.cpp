#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000

using namespace std;

int N, L, H;
int heightestIdx = 0;
vector<int> pillars(MAX + 1, 0);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> L >> H;
        pillars[L] = H;
        if (pillars[heightestIdx] < H)
            heightestIdx = L;
    }

    int totalSize = 0;
    int maxHeight = 0;

    for (int i = 0; i <= heightestIdx; i++)
    {
        if (pillars[i] > maxHeight)
            maxHeight = pillars[i];
        totalSize = totalSize + maxHeight;
    }

    maxHeight = 0;
    for (int i = 20; i > heightestIdx; i--)
    {
        if (pillars[i] > maxHeight)
            maxHeight = pillars[i];
        totalSize = totalSize + maxHeight;
    }

    cout << totalSize;

    return 0;
}