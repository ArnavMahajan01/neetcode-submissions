class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sChars;
        unordered_map<char,int> tchars;

        if (s.length() != t.length()) {
            return false;
        }


        for(int i =0; i< s.size(); i++){
            sChars[s[i]]++;
            tchars[t[i]]++;
        }

        return sChars == tchars;
    }
};
