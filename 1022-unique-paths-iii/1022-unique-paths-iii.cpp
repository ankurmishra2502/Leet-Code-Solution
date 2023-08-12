class Solution {
public:
    int solve(vector<vector<int>> &grid,int &cntZero,int startx,int starty,int count){
        if(startx<0 || startx>=grid.size() || starty<0 || starty>=grid[0].size()|| grid[startx][starty]== -11 || grid[startx][starty]==-1){
            return 0;
        }
        if(grid[startx][starty]==2){
            if(count == cntZero) return 1;
            else return 0;
        }
        grid[startx][starty]= -11;
        int ans=0;
        ans= solve(grid,cntZero,startx+1,starty,count+1);
        ans= ans+solve(grid,cntZero,startx-1,starty,count+1);
        ans= ans+solve(grid,cntZero,startx,starty+1,count+1);
        ans= ans+solve(grid,cntZero,startx,starty-1,count+1);
        grid[startx][starty]=0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int countZero=1;
        int startx;
        int starty;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                else if(grid[i][j]==0) countZero++;
            }
        }
        return solve(grid,countZero,startx,starty,0);
    }
};