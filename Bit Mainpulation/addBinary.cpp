#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * This function adds two binary strings together and returns the result as a string.
     * It uses a carry variable to keep track of any bits that need to be carried over
     * from one iteration of the loop to the next.
     * The function iterates over the two strings from right to left, adding the corresponding bits
     * together and keeping track of the carry.
     * The result is built up as a string from left to right, with the most significant bit
     * being added first.
     * @param a The first binary string to be added.
     * @param b The second binary string to be added.
     * @return The result of adding the two binary strings together as a string.
     */
    string addBinary(string a, string b)
    {
        int m = a.size();
        int n = b.size();

        int carry = 0;

        int i = m - 1, j = n - 1;
        string result = "";

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = 0;
            if (i >= 0)
            {
                sum += (a[i] - '0');
                i--;
            }
            if (j >= 0)
            {
                sum += (b[j] - '0');
                j--;
            }
            if (carry)
            {
                sum += carry;
                carry = carry / 2;
            }
            result = to_string(sum % 2) + result;
            carry = sum / 2;
        }
        return result;
    }
};