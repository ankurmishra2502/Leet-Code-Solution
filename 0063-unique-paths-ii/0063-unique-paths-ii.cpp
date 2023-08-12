class Solution {
public:
    int solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>& dp){
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()) return 0;
        if(dp[row][col]!= -1) return dp[row][col];
        if(row==grid.size()-1 && col==grid[0].size()-1 && grid[row][col]==0) return 1;
        if(grid[row][col]==1) return 0;
        int down=solve(grid,row+1,col,dp);
        int right=solve(grid,row,col+1,dp);
        return dp[row][col]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
       vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
     return solve(grid,0,0,dp);   
    }

};