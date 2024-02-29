#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10000;
int N;
int cnt[MAX + 1] = {
    0,
};

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        cnt[input]++;
    }
    for (int i = 1; i <= MAX; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << i << "\n";
        }
    }

    return 0;
}