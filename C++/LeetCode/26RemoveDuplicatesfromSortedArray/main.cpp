class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;

        int p = 1;
        for (int i = 1; i < len; i++)
        {
            if (nums[i - 1] != nums[i])
            {
                nums[p++] = nums[i];
            }
        }

        return p;
    }
};