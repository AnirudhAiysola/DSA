class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxElement = 0, maxCount = 0;
        long long ans = 0;
        // find max element
        for (auto it : nums)
            maxElement = max(it, maxElement);
        int i = 0, j = 0;
        // sliding window
        while (j < n)
        {
            if (nums[j] == maxElement)
            {
                maxCount++;
            }
            while (i <= j && maxCount >= k)
            {
                ans += (n - j);
                // shrink window
                if (nums[i] == maxElement)
                {
                    maxCount--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};