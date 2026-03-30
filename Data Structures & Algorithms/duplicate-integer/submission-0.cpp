class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numLength;

        for(int num: nums){
            if(numLength.count(num)){
                return true;
            }
            numLength.insert(num);
        }

        return false;
    }
};