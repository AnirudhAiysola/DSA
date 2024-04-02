class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        unordered_map<char, char> m;
        int i = 0;
        string str = "";
        unordered_set<char> st;
        while (i < n)
        {
            if (m.count(s[i]))
            {
                if (m[s[i]] != t[i])
                    return false;
            }
            else
            {
                if (st.count(t[i]))
                    return false;
            }
            m[s[i]] = t[i];
            st.insert(t[i]);
            i++;
        }
        return true;
    }
};