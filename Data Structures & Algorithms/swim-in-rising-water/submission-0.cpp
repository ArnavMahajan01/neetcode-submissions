class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int minH = grid[0][0], maxH = grid[0][0];

        for(int i =0; i < n; i++){
            for(int j =0; j < n; j++){
                minH = min(minH, grid[i][j]);
                maxH = max(maxH, grid[i][j]);
            }
        }

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = minH; i < maxH; i++){
            if(dfs(grid, visited, 0, 0, i)){
                return i;
            }
            for(int j = 0; j< n; j++){
                fill(visited[j].begin(), visited[j].end(), false);
            }
        }

    }

    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visit,
                                        int r, int c, int t) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid.size() || visit[r][c] || grid[r][c] > t) {
            return false;
        }
        if (r == grid.size() - 1 && c == grid.size() - 1) {
            return true;
        }
        visit[r][c] = true;
        return dfs(grid, visit, r + 1, c, t) ||
               dfs(grid, visit, r - 1, c, t) ||
               dfs(grid, visit, r, c + 1, t) ||
               dfs(grid, visit, r, c - 1, t);
    }

};
