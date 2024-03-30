class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int n = s.size();
        int ans = 0;
        // hashmap to store elements and their frequencies
        unordered_map<char, int> m;
        // sliding window
        int i = 0, j = 0;
        while (j < n)
        {
            m[s[j]]++;
            while (m.size() > k)
            {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};