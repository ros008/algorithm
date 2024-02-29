#include <iostream>
#include <vector>

using namespace std;

bool isPrimeNumber(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primeNumbers(int num)
{
    vector<int> arr(num + 1, 1);
    arr[0] = 0;
    arr[1] = 0;
    for (int i = 2; i * i <= num; i++)
    {
        for (int j = i * i; j <= num; j += i)
        {
            if (arr[j] == 1)
            {
                arr[j] = 0;
            }
        }
    }
    for (int i = 1; i <= num; i++)
    {
        if (arr[i] == 1)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int num = 97;

    cout << isPrimeNumber(num) << "\n";
    primeNumbers(num);

    return 0;
}