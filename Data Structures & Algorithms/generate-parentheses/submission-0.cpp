class Solution {
public:
    vector<string> result;

    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return result;
    }

    void dfs(string curr, int open, int closed, int n){
        
        if(curr.length() == 2*n){
            result.push_back(curr);
            return;
        }
        
        if(open < n){
            dfs(curr + "(", open + 1, closed, n);
        }

        if(closed < open){
            dfs(curr + ")", open, closed + 1, n);
        }

    }
};
