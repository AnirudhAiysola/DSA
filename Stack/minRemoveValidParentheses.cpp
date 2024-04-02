class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        // stack to balance the parentheses
        stack<pair<char, int>> st;
        // set to store the indices that will be skipped in the final result string
        unordered_set<int> skip;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push({s[i], i});
            }
            else if (s[i] == ')')
            {
                if (st.empty())
                {
                    skip.insert(i);
                }
                else
                {
                    st.pop();
                }
            }
        }
        while (!st.empty())
        {
            skip.insert(st.top().second);
            st.pop();
        }
        string result = "";

        for (int i = 0; i < n; i++)
        {
            if (!skip.count(i))
            {
                result += s[i];
            }
        }
        return result;
    }
};