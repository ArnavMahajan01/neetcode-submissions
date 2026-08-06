class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> isNum;
        for(int num: nums){
            if(isNum.count(num))
                return true;
            isNum.insert(num);
        }

        return false;
    }
};