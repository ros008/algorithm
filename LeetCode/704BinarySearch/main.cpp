class Solution
{
public:
    int binarySearch(vector<int> nums, int target, int len)
    {
        int start = 0, end = len - 1;

        while (end >= start)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int ans = binarySearch(nums, target, nums.size());
        return ans;
    }
};