class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        return dfs(nums, 0);
    }

    int dfs(vector<int>&nums, int index){
        if(nums.size () <= index)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];
        
        dp[index] = max(dfs(nums, index + 1), nums[index] + dfs(nums, index+2));

        return dp[index];
    }
};
