#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times)
{
    long long answer = 0;
    sort(times.begin(), times.end());

    long long min = 1;
    long long max = n * (long long)times[times.size() - 1];

    while (min <= max)
    {
        long long mid = (min + max) / 2;
        long long tmp = 0;
        for (int i = 0; i < times.size(); i++)
        {
            tmp += (mid / (long long)times[i]);
        }
        if (tmp >= n)
        {
            max = mid - 1;
            answer = mid;
        }
        else
        {
            min = mid + 1;
        }
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<int> times = {7, 10};

    cout << solution(n, times);

    return 0;
}