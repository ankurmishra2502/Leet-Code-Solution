class Solution {
public:
    int solve(int present,vector<int>&nums,int indx,vector<vector<int>>&dp){
        if(indx==nums.size()-1) return 0;
        if(dp[indx][present]!= -1) return dp[indx][present];
        if(present!=nums[indx+1]) return solve(present,nums,indx+1,dp);
        int min_step=INT_MAX;
        for(int i=1;i<=3;i++){
            if(i!=present){
                if(nums[indx]!=i){
                    min_step= min(min_step,1+ solve(i,nums,indx,dp));
                }
            }
        }
        return dp[indx][present]=min_step;
    }
    int minSideJumps(vector<int>& obs) {
        int n=obs.size();
        vector<vector<int>> dp(n+5,vector<int>(4,-1));
        return solve(2,obs,0,dp);
    }
};