#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * This function takes a vector of integers as input and returns the single number that appears only once in the vector.
     * All other numbers appear twice.
     * The function uses bitwise XOR operation to achieve this.
     * Time complexity of this function is O(n) where n is the size of the input vector.
     */
    int singleNumber(vector<int> &nums)
    {
        int n = nums.size();

        int ans = nums[0];

        for (int i = 1; i < n; i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};