class Solution {
public:
    int direction[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int numIslands(vector<vector<char>>& grid) {    
        int cnt = 0;
        int rows = grid.size(), col = grid[0].size();

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == '1')
                    cnt++;
                    dfs(grid, i, j, cnt);
            }
        }

        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int row, int col, int cnt){
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0')
            return;
        
        grid[row][col] = '0';

        for(int i = 0; i < 4; i++){
            dfs(grid, row + direction[i][0], col + direction[i][1], cnt);
        }
    }
};
