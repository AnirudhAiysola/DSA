class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.size();
        int ans = 0, count = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                count++;
            }
            else if (s[i] == ')')
            {
                count--;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};