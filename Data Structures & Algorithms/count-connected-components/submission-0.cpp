class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> edgeVal(n);
        vector<bool> visited(n, false);


        for(const auto& edge: edges ){
            edgeVal[edge[0]].push_back(edge[1]);
            edgeVal[edge[1]].push_back(edge[0]);
        }

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(edgeVal, visited, i);
                cnt++;
            }
            
        }

        return cnt;
    }

    void dfs(vector<vector<int>>& edges, vector<bool>& visited, int i){
        visited[i] = true;

        for(int node: edges[i]){
            if(!visited[node])
                dfs(edges, visited, node);
        }
    }
};
