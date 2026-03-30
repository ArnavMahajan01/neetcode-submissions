class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> values;
        vector<int> result(temperatures.size(), 0);

        for(int i = 0; i<temperatures.size(); i++){
            int t = temperatures[i];

            while(!values.empty() && t > values.top().first){
                auto pair = values.top();
                values.pop();
                result[pair.second] = i - pair.second;
            }
            values.push({temperatures[i], i});
        }

        return result;
    }
};
