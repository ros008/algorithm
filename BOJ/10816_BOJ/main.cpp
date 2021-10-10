#include <iostream>
#include <vector>

#define MAX 10000000

using namespace std;

int N, M, answer = 0;
int num[MAX * 2 + 10];

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        num[input + MAX]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;
        cout << num[input + MAX] << " ";
    }

    return 0;
}