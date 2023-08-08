class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();

        vector<vector<int>> ans(row,vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int r= i-1;
                int c= j-1;
                unordered_map<int,int> mp;
                while(r>=0 && c>=0){
                    mp[grid[r][c]]++;
                    r--;
                    c--;
                }
                int nr= i+1;
                int nc= j+1;
                unordered_map<int,int> mp1;
                while(nr<row && nc<col){
                    mp1[grid[nr][nc]]++;
                    nr++;
                    nc++;
                }
                int first=mp.size();
                int second=mp1.size();
                ans[i][j]= abs(first-second);
            }
        }
        return ans;
    }
};