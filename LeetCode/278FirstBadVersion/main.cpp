// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int answer = 1;
        long long start = 1, end = n;
        while (end >= start)
        {
            long long mid = (start + end) / 2;
            if (isBadVersion(mid) == true)
            {
                if (mid - 1 >= 1 && isBadVersion(mid - 1) == false)
                {
                    answer = mid;
                    break;
                }
                end = mid - 1;
            }
            else
            {
                if (mid + 1 <= n && isBadVersion(mid + 1) == true)
                {
                    answer = mid + 1;
                    break;
                }
                start = mid + 1;
            }
        }
        return answer;
    }
};