#include <iostream>

using namespace std;

int main()
{
    long long M, N;
    cin >> M >> N;
    if (M > N)
        cout << N * 2 - 1 << "\n";
    else
        cout << (M - 1) * 2 << "\n";

    if (M == N)
    {
        if (M % 2 == 1)
            cout << (M - 1) / 2 + 1 << " " << (M - 1) / 2 + 1;
        else
            cout << (M) / 2 + 1 << " " << (M) / 2;
    }
    else
    {
        if (N > M)
        {
            if (M % 2 == 0)
                cout << (M) / 2 + 1 << " " << (M) / 2;
            else
                cout << (M - 1) / 2 + 1 << " " << (M - 1) / 2 + 1 + N - M;
        }
        else
        {
            if (N % 2 == 0)
                cout << (N) / 2 + 1 << " " << (N) / 2;
            else
                cout << (N - 1) / 2 + 1 + M - N << " " << (N - 1) / 2 + 1;
        }
    }

    return 0;
}