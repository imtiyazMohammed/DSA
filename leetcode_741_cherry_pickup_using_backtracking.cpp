class Solution {
public:
    
    int maxcc = 0;
    
    // n-1,n-1 to 0,0
    void helper(int row, int col, vector<vector<int>> &grid, int ccsf){
        
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1){
            return;
        }
        
        if(row == 0 && col == 0){
            maxcc = max(maxcc, ccsf);
            return;
        }
        
        int cherries = grid[row][col];
        grid[row][col] = 0;
        helper(row, col-1, grid, ccsf+cherries);
        helper(row-1, col, grid, ccsf+cherries);
        grid[row][col] = cherries;
    }
    
    
    // 0,0 to n-1,n-1
    void solve(int row, int col, vector<vector<int>> &grid, int ccsf){
        
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == -1){
            return;
        }
        
        if(row == grid.size()-1 && col == grid[0].size()-1){
            helper(row, col, grid, ccsf);
        }
        
        int cherries = grid[row][col];
        grid[row][col] = 0;
        solve(row, col+1, grid, ccsf+cherries);
        solve(row+1, col, grid, ccsf+cherries);
        grid[row][col] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.size() == 1){
            if(grid[0][0] == 1) return 1;
            else return 0;
        }
        solve(0, 0, grid, 0);
        return maxcc;
    }
};
