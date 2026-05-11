class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjencyEdges(n+1);

        for(auto& edge:edges){
            int i = edge[0], j = edge[1];
            adjencyEdges[i].push_back(j);
            adjencyEdges[j].push_back(i);
            vector<bool> visit(n + 1, false);

            if(dfs(i, -1, adjencyEdges, visit)){
                return {i, j};
            }
        }

        return {};

    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit) {
        if (visit[node]) return true;
        visit[node] = true;
        for(int neighbour: adj[node]){
            if (neighbour == parent) continue;
            if (dfs(neighbour, node, adj, visit)) return true;
        }

        return false;
    }

};
