class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numFreq;

        for(auto num: nums){
            numFreq[num]++;
        }

        priority_queue<pair<int,int>> pq;


        for (auto &p : numFreq) {
            pq.push({p.second, p.first}); // (freq, num)
        }

        // 3. Extract top k
        vector<int> result;
        while (k-- && !pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};
