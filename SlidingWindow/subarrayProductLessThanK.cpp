class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int i = 0, j = 0, product = 1;
        int ans = 0;
        // sliding window
        while (j < n)
        {
            product *= nums[j];
            while (product >= k && i < n)
            {
                product = product / nums[i];
                i++;
            }
            if (product == 0)
                product = 1;
            if (product < k)
            {
                ans += j - i + 1;
            }
            j++;
        }
        return ans;
    }
};