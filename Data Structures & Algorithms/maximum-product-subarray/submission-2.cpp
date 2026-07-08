class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int minVal = 1, maxVal = 1;

        for(int& num: nums){
            int tmp = maxVal * num;
            maxVal = max(num, max(minVal * num, maxVal * num));
            minVal = min(num, min(minVal * num, tmp));

            res = max(res, maxVal);
        }

        return res;
    }
};
