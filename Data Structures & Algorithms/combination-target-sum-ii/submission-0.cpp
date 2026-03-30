class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int i, int target, vector<int>& subset){
        if(target == 0){
            res.push_back(subset);
            return;
        }

        if(i >= nums.size() || target < 0){
            return;
        }

        // include
        subset.push_back(nums[i]);
        dfs(nums, i+1, target - nums[i], subset);
        subset.pop_back();

        // skip duplicates
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        // exclude
        dfs(nums, i+1, target, subset);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        dfs(candidates, 0, target, subset);
        return res;
    }
};