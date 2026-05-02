class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for(int i =0; i<strs.size(); i++){
            string sortedStr = strs[i];
            sort(sortedStr.begin(), sortedStr.end());
            anagrams[sortedStr].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto& ana: anagrams){
            result.push_back(ana.second);
        }

        return result;
    }
};
