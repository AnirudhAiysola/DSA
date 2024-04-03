class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        // tokenzie the string with delimeter '/'
        stringstream ss(path);
        string token = "";
        while (getline(ss, token, '/'))
        {
            if (token == "" || token == ".")
                continue;
            if (token == "..")
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(token);
            }
        }
        if (st.empty())
            return "/";
        string result;
        while (!st.empty())
        {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};