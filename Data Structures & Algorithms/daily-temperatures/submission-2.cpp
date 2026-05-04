class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> val;
        vector<int> res(temperatures.size(), 0);

        int maxTemp = 0;
        int cnt = 0;

        for(int i =0; i<temperatures.size(); i++){
            auto temp = temperatures[i];
            while(!val.empty() && temp > val.top().first){
                auto t = val.top();
                val.pop();
                res[t.second] = i - t.second;
            }
            val.push({temp, i});
        }

        return res;
    }
};
