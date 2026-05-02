class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int maxSum = nums[0];

        for(int num: nums){
            if(res < 0)
                res = 0;
            
            res += num;
            maxSum = max(maxSum, res);
        }

        return maxSum;
    }
};
