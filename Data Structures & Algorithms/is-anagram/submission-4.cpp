class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> scharacters;
        unordered_map<char, int> tcharacters;

        for(int i =0; i<s.length(); i++){
            scharacters[s[i]]++;
            tcharacters[t[i]]++;
        }

        if(s.length() != t.length())
            return false;

        return scharacters == tcharacters;
    }
};
