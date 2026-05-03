class Solution {
public:
    int directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j =0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }

        return cnt;
    }

    void dfs(int row, int col, vector<vector<char>>& grid){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' )
            return;

        grid[row][col] = '0';

        for(int i = 0; i<4; i++){
            dfs(row + directions[i][0],col + directions[i][1],grid);
        }
    }
};
