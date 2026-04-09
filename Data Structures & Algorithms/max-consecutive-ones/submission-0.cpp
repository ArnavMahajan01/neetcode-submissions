class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxNum = 0, cnt = 0;

        for(auto num: nums){
            if(num == 0){
                maxNum = max(maxNum, cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }

        return max(maxNum, cnt);
    }
};