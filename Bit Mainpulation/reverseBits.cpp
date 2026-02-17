#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * Reverses the bits of a given 32-bit signed integer.
     *
     * Time complexity: O(1) since we are only iterating over 32 bits.
     * Space complexity: O(1) since we are only using a single variable to store the result.
     */
    int reverseBits(int n)
    {
        string binary = "";

        for (int i = 0; i < 32; i++)
        {
            binary += ((1 << i) & n) ? '1' : '0';
        }
        int result = 0;

        for (int i = 0; i < 32; i++)
        {
            if (binary[31 - i] == '1')
            {
                result = result | (1 << i);
            }
        }
        return result;
    }
};