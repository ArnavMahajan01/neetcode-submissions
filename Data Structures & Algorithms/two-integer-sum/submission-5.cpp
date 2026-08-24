class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapTwoSum;

        for(int i =0; i<nums.size(); i++){
            int diff = target - nums[i];
            if(mapTwoSum.find(diff) != mapTwoSum.end()){
                return {mapTwoSum[diff], i};
            }
            mapTwoSum[nums[i]] =  i;
        }

        return {};
    }
};
