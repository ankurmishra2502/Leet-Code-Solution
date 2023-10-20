class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size(),vector<int>(grid[0].size(),1));
        int mod = 12345;
        long long product=1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans[i][j]*=product;
                ans[i][j]%=mod;
                product*=grid[i][j];
                product%=mod;
            }
        }
        product=1;
        for(int i=grid.size()-1;i>=0;i--){
            for(int j=grid[0].size()-1;j>=0;j--){
                ans[i][j]*=product;
                ans[i][j]%=mod;
                product*=grid[i][j];
                product%=mod;
            }
        }
        return ans;
    }
};