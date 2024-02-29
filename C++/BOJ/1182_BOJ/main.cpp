#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> arr;
int cnt = 0;

void solve(int idx, int sum)
{
    if (idx == N)
        return;
    if (sum + arr[idx] == S)
        cnt++;

    solve(idx + 1, sum);
    solve(idx + 1, sum + arr[idx]);
}

int main()
{
    cin >> N >> S;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }

    solve(0, 0);

    cout << cnt << "\n";

    return 0;
}