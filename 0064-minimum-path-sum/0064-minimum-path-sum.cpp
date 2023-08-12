class Solution {
public:
    int final_val=INT_MAX;
    int solve(vector<vector<int>> &grid,int row,int col,vector<vector<int>> &dp){
        if(row<0 || row>= grid.size() || col<0 || col>=grid[0].size()){
            return INT_MAX;
        }
        if(dp[row][col]!= -1) return dp[row][col];
        if(row== grid.size()-1 && col ==grid[0].size()-1) return grid[row][col];
        return dp[row][col]=grid[row][col]+min(solve(grid,row,col+1,dp),solve(grid,row+1,col,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size()+1,vector<int> (grid[0].size()+1,-1));
        return solve(grid,0,0,dp);
    }
};