class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        // hashmap to store frequencies of elements
        unordered_map<int, int> m;
        int i = 0, j = 0;
        int maxLength = 0;
        // sliding window
        while (j < n)
        {
            m[nums[j]]++;
            while (m[nums[j]] > k && i < n)
            {
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        return maxLength;
    }
};