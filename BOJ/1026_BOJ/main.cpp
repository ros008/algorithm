#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> A, B;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        A.push_back(input);
    }
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        B.push_back(input);
    }
    sort(B.begin(), B.end());
    sort(A.begin(), A.end(), greater<int>());

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i] * B[i];
    }
    cout << sum << "\n";

    return 0;
}