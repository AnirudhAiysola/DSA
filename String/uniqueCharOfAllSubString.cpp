class Solution
{
public:
    int uniqueLetterString(string s)
    {
        int n = s.size();
        long long ans = 0;
        // unique characters of all substrings of a given string is equal to contribution of each unique character in the string
        // the contribution of a character is equal to its left window multiplied by right window
        vector<vector<int>> hashmap(26);
        // push -1 to get the left window length when at 0 position
        for (int i = 0; i < 26; i++)
        {
            hashmap[i].push_back(-1);
        }
        // store all the indices of the character
        for (int i = 0; i < n; i++)
        {
            hashmap[s[i] - 'A'].push_back(i);
        }
        // push length of the string to get the right window when at n-1 position
        for (int i = 0; i < 26; i++)
        {
            hashmap[i].push_back(n);
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j < hashmap[i].size() - 1; j++)
            {
                ans += (hashmap[i][j] - hashmap[i][j - 1]) * (hashmap[i][j + 1] - hashmap[i][j]);
            }
        }
        return ans;
    }
};