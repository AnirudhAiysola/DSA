#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Returns the Hamming weight of a given integer n.
     * The Hamming weight of an integer is the number of bits set to 1 in its binary representation.
     * Time complexity: O(1) since we are only iterating over 32 bits.
     * Space complexity: O(1) since we are only using a single variable to store the result.
     */
    int hammingWeight(int n)
    {
        int ans = 0;

        for (int i = 0; i < 32; i++)
        {
            if ((1 << i) & n)
                ans++;
        }
        return ans;
    }
};