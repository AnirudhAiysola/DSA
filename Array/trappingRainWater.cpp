class Solution
{
public:
    int trap(vector<int> &heights)
    {
        int n = heights.size();
        int ans = 0;
        // to find the total rain water we need to find the max height to the left and right of the current block
        // rain water trapped would be min(left,right) - current block height
        vector<int> nextGreaterLeft(n);
        vector<int> nextGreaterRight(n);
        int leftMax = 0;
        int rightMax = 0;

        for (int i = 0; i < n; i++)
        {
            nextGreaterLeft[i] = leftMax;
            leftMax = max(leftMax, heights[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            nextGreaterRight[i] = rightMax;
            rightMax = max(rightMax, heights[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int val = min(nextGreaterLeft[i], nextGreaterRight[i]) - heights[i];
            if (val < 0)
                val = 0;
            ans += val;
        }
        return ans;
    }
};