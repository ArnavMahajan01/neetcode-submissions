class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int i, int target, vector<int>& subset) {
        if(target == 0){
            res.push_back(subset);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i, target - nums[i], subset);
        subset.pop_back();
        dfs(nums, i+1, target, subset);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subset;
        dfs(nums, 0, target, subset);
        return res;
    }
};
