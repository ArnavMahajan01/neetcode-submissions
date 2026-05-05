class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int total = m + n;
        int half = (total + 1) / 2;

        int low = 0, high = m;

        while (low <= high) {
            int i = (low + high) / 2;
            int j = half - i;

            int left1  = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i]     : INT_MAX;

            int left2  = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j]     : INT_MAX;

            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                else
                    return max(left1, left2);
            }
            else if (left1 > right2) {
                high = i - 1;
            }
            else {
                low = i + 1;
            }
        }

        return 0;
    }
};