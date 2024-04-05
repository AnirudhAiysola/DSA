class Solution
{
public:
    string makeGood(string s)
    {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                char lower = tolower(s[i]);
                char upper = toupper(s[i]);
                // check
                if (islower(s[i]) && st.top() == upper)
                {
                    st.pop();
                }
                else if (isupper(s[i]) && st.top() == lower)
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        string result = "";
        if (st.empty())
            return result;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};