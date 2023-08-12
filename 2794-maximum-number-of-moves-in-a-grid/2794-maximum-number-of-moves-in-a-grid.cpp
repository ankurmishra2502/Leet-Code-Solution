class Solution {
public:
    int solve(vector<vector<int>> &grid,int row,int col,int value,vector<vector<int>>&dp){
        if(col==grid[0].size()) return 0;
        if(row<0 || row>=grid.size() || col<0 || col>=grid[0].size()){
            return 0;
        }
        if(dp[row][col]!= -1) return dp[row][col];
        int right=0,dia1=0,dia2=0;
        if( row-1>=0 && col+1<grid[0].size() && grid[row][col]<grid[row-1][col+1]){
            right= 1+ solve(grid,row-1,col+1,grid[row][col],dp);
        }
         if(row+1 <grid.size() && col+1<grid[0].size() && grid[row][col]<grid[row+1][col+1]){
            dia1= 1+ solve(grid,row+1,col+1,grid[row][col],dp);
        }
         if(row<grid.size() && col+1 <grid[0].size() && grid[row][col]<grid[row][col+1]){
            dia2= 1+ solve(grid,row,col+1,grid[row][col],dp);
        }
        return dp[row][col]=max(right,max(dia1,dia2));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int val=0;
        vector<vector<int>> dp(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        for(int i=0;i<grid.size();i++){
            val= max(val,solve(grid,i,0,grid[i][0],dp));
        }
        return val;
    }
};