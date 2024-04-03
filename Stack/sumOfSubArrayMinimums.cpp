class Solution
{
    const int MOD = 1e9 + 7;

private:
    vector<int> NSL(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nsl(n);
        stack<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = st.top();
            }
            st.push(i);
        }
        return nsl;
    }
    vector<int> NSR(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> nsr(n);
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nsr[i] = nums.size();
            }
            else
            {
                nsr[i] = st.top();
            }
            st.push(i);
        }
        return nsr;
    }

public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        long long ans = 0;
        vector<int> nsl = NSL(arr);
        vector<int> nsr = NSR(arr);

        for (int i = 0; i < n; i++)
        {
            long long d1 = i - nsl[i];
            long long d2 = nsr[i] - i;
            long long total = d1 * d2;
            long long ways = (arr[i] * total);

            ans = (ans + ways) % MOD;
        }
        return ans;
    }
};