class Solution {
public:

    int directions[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = dfs(i, j, grid);
                    if(maxArea < area)
                        maxArea = area;
                }
            }
        }

        return maxArea;    
    }

    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || col < 0 || col >= grid[0].size() || row >= grid.size() || grid[row][col] == 0)
            return 0;

        grid[row][col] = 0;
        int area = 1;

        for(int r =0; r<4; r++){
            area += dfs(row + directions[r][0], col + directions[r][1], grid);          
        }

        return area;
    }
};
