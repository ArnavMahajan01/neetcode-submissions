class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int start, int target, vector<int>& subset){
        if(target == 0){
            res.push_back(subset);
            return;
        }

        for(int j = start; j < nums.size(); j++){

            // skip duplicates
            if(j > start && nums[j] == nums[j-1])
                continue;

            if(nums[j] > target)
                break;

            subset.push_back(nums[j]);
            dfs(nums, j+1, target - nums[j], subset);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        dfs(candidates, 0, target, subset);
        return res;
    }
};