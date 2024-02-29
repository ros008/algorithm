#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500

using namespace std;

int W, H;

int main()
{
    cin >> H >> W;
    vector<int> heights;
    for (int i = 0; i < W; i++)
    {
        int input;
        cin >> input;
        heights.push_back(input);
    }

    vector<int> heightL(W + 1);
    vector<int> heightR(W + 1);
    int maxHeight = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        if (maxHeight < heights[i])
            maxHeight = heights[i];
        heightL[i] = maxHeight;
    }

    maxHeight = 0;
    for (int i = heights.size() - 1; i >= 0; i--)
    {
        if (maxHeight < heights[i])
            maxHeight = heights[i];
        heightR[i] = maxHeight;
    }

    int totalSize = 0;
    int boxSize = 0;
    for (int i = 0; i < heights.size(); i++)
    {
        boxSize += heights[i];
        totalSize += min(heightL[i], heightR[i]);
    }

    cout << totalSize - boxSize;

    return 0;
}