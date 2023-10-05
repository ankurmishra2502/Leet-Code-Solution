class Solution {
public:
    int solve(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp){
        int count=0;
        queue<pair<int,int>> q;
        dp[row][col]=1;
        int newRow[4]={-1,0,1,0};
        int newCol[4]={0,1,0,-1};
        q.push({row,col});
        count++;
        while(!q.empty()){
            auto val= q.front();
            int r= val.first;
            int c= val.second;
            q.pop();
           for(int i=0;i<4;i++){
               int nr= r+newRow[i];
               int nc= c+newCol[i];
               if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && dp[nr][nc]==0 && grid[nr][nc]==1){
                   q.push({nr,nc});
                   dp[nr][nc]=1;
                   count++;
               }
           }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int count=0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(dp[i][j]==0 && grid[i][j]==1){
                    int cnt=solve(i,j,grid,dp);
                    count= max(cnt,count);
                }
            }
        }
        return count;
    }
};