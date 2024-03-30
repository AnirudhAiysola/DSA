class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        // hashmap to store elements and their frequencies
        unordered_map<int, int> m;
        // calculate the distinct elements in the array
        for (auto it : nums)
            m[it]++;
        int d = m.size();
        m.clear();
        // sliding window
        int i = 0, j = 0;
        while (j < n)
        {
            m[nums[j]]++;
            while (i <= j && m.size() == d)
            {
                ans += n - j;
                m[nums[i]]--;
                if (m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};