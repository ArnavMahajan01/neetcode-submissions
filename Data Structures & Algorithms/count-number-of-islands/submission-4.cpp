class Solution {
public:
    int directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    bfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void bfs(int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row, col});

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int rowNew = node.first, colNew = node.second;

            for(int i = 0; i< 4; i ++){
                int nr = rowNew + directions[i][0], nc = colNew + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1'){
                    q.push({nr, nc});
                    grid[nr][nc] = '0';
                }
            }
        }
    }
};
