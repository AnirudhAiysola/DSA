class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // apply binary search on lesser size vector to improve TC
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int elementsOnLeft = (n1 + n2) / 2;
        while (low <= high)
        {
            int mid1 = low + (high - low) / 2;
            int mid2 = elementsOnLeft - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            // check if valid
            if (l1 <= r2 && l2 <= r1)
            {
                return ((n1 + n2) % 2 == 0) ? ((max(l1, l2) + min(r1, r2)) / 2.0) : min(r1, r2);
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};