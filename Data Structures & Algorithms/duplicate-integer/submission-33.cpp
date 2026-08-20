class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> isPresent;

        for(int& num: nums){
            if(isPresent.count(num))
                return true;
            isPresent.insert(num);
        }

        return false;
    }
};