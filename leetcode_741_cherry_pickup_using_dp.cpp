class Solution {
public:
    int dp[50][50][50][50];
    
    int solve(int r1, int c1, int r2, int c2, vector<vector<int>> &grid){
        
        if(r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1){
            return INT_MIN;
        }
        
        if(r1 == grid.size()-1 && c1 == grid[0].size()-1){
            return grid[r1][c1];
        }
        
        if(dp[r1][c1][r2][c2] != 0){
            return dp[r1][c1][r2][c2];
        }
        
        int cherries = 0;
        
        if(r1 == r2 && c1 == c2){
            cherries += grid[r1][c1]; // if both arrive at same point, add only any one
        }
        else{
            cherries += (grid[r1][c1] + grid[r2][c2]); // if both are at different points, add both
        }
        
        int f1 = solve(r1, c1+1, r2, c2+1, grid); // both moves horizontally
        int f2 = solve(r1+1, c1, r2, c2+1, grid); // one moves vertical, other moves horizontal
        int f3 = solve(r1+1, c1, r2+1, c2, grid); // both moves vertically
        int f4 = solve(r1, c1+1, r2+1, c2, grid); // one moves horizontal and other moves vertical
        
        cherries += max(f1, max(f2, max(f3,f4)));
        dp[r1][c1][r2][c2] = cherries;
        return cherries;
        
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        
        for(int i = 0; i < 50; i++){
            for(int j = 0; j < 50; j++){
                for(int k = 0; k < 50; k++){
                    for(int l = 0; l < 50; l++){
                        dp[i][j][k][l] = 0;
                    }
                }
            }
        }
        
        int ans = solve(0,0,0,0, grid);
        if(ans < 0) return 0;
        return ans;
    }
};
