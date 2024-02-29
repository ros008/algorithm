#include <iostream>
#include <vector>

#define MAX 10000000

using namespace std;

int N, M;
int check[MAX * 2 + 1] = {0};

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        check[input + MAX] = 1;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        if (check[input + MAX])
            cout << "1 ";
        else
            cout << "0 ";
    }

    return 0;
}