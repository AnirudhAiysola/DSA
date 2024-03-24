class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int m = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[abs(nums[i])] < 0)
            {
                return abs(nums[i]);
            }
            else
            {
                nums[abs(nums[i])] = m * nums[abs(nums[i])];
            }
        }
        return -1;
    }
};