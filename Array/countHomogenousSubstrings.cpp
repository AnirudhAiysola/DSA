#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    typedef long long ll;
    /**
     * Returns the count of homogenous substrings in string s.
     * A homogenous substring is a substring which consists of the same character.
     * The count is calculated using the formula (count * (count + 1)) / 2.
     * The result is taken modulo 1e9+7 to prevent overflow.
     */
    int countHomogenous(string s)
    {
        int n = s.size();
        char prev = s[0];
        ll count = 1, ans = 0;

        for (int i = 1; i < n; i++)
        {
            if (prev == s[i])
            {
                count++;
            }
            else
            {
                prev = s[i];
                ll val = ((count) * (count + 1) / 2) % MOD;
                ans = (ans + val) % MOD;
                count = 1;
            }
        }
        if (count >= 1)
        {
            ll val = ((count) * (count + 1) / 2) % MOD;
            ans = (ans + val) % MOD;
        }
        return ans;
    }
};