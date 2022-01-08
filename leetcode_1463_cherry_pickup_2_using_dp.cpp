class Solution {
public:
    
    int dp[80][80][100];
    
    int solve(vector<vector<int>> &grid, int c1, int c2, int r){
        int n = grid.size();
        int m = grid[0].size();
        
        if(r == n) return 0;
        
        if(dp[c1][c2][r] != -1) return dp[c1][c2][r];
        
        int cherries = 0;
        
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int col_1 = c1+i;
                int col_2 = c2+j;
                
                if(col_1 >= 0 && col_1 < m && col_2 >= 0 && col_2 < m){
                    cherries = max(cherries, solve(grid, col_1, col_2, r+1));
                }
            }
        }
        
        if(c1 == c2) cherries += grid[r][c1];
        else cherries += (grid[r][c1] + grid[r][c2]);
        
        return dp[c1][c2][r] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, 0, grid[0].size()-1, 0);
    }
};
