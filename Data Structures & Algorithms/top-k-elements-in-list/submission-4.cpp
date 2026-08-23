class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;

        for(int& num: nums){
            numCount[num]++;
        }

        vector<pair<int, int>> numsRe;

        for(auto& num: numCount){
            numsRe.push_back({num.second, num.first});
        }

        sort(numsRe.begin(), numsRe.end(), greater<pair<int, int>>());
        vector<int> result;
        for(int i =0; i<k; i++){
            result.push_back(numsRe[i].second);
        }

        return result;

    }
};
