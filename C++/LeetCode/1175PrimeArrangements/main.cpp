class Solution
{
public:
    int numPrimeArrangements(int n)
    {
        if (n == 1)
            return 1;
        vector<int> arr(n + 1, 1); // 1이면 소수, 0이면 소수아님
        arr[0] = 0;
        arr[1] = 0;
        for (int i = 2; i * i <= n; i++)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (arr[j] == 1)
                {
                    arr[j] = 0;
                }
            }
        }

        int primeCnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i] == 1)
            {
                primeCnt++;
            }
        }
        int notPrimeCnt = n - primeCnt;
        long long int answer = 1;
        while (primeCnt)
        {
            answer = (answer * primeCnt) % 1000000007;
            primeCnt--;
        }
        while (notPrimeCnt)
        {
            answer = (answer * notPrimeCnt) % 1000000007;
            notPrimeCnt--;
        }

        return answer % 1000000007;
    }
};