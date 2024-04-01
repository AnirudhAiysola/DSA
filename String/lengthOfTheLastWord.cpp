class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 0)
            return 0;
        string str = "";
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                continue;
            int j = i;
            while (j >= 0 && s[j] != ' ')
            {
                str += s[j];
                j--;
            }
            break;
        }
        return str.size();
    }
};