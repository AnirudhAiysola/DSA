class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> st;
        // push all opening brackets into the stack
        // if we encounter closing bracket we check if top of stack is corresponding opening bracket
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty())
                    return false;
                if ((s[i] == ')' && st.top() != '(') || (s[i] == ']' && st.top() != '[') || (s[i] == '}' && st.top() != '{'))
                {
                    return false;
                }
                else
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }
};