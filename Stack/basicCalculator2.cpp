class Solution
{
public:
    int calculate(string s)
    {
        int n = s.size();
        long long int ans = 0, num = 0;
        stack<int> st;
        char sign = '+';

        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1)
            {
                if (sign == '+')
                {
                    st.push(num); // the current number will b added
                }
                else if (sign == '-')
                {
                    st.push(-num); // the current number will be subtracted
                }
                else if (sign == '*')
                {
                    int curr = st.top();
                    st.pop();
                    st.push(curr * num); // the current number is multiplied with the top of stack
                }
                else if (sign == '/')
                {
                    int curr = st.top();
                    st.pop();
                    st.push(curr / num); // the current number is divided with the top of stack
                }
                num = 0;
                sign = s[i];
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};