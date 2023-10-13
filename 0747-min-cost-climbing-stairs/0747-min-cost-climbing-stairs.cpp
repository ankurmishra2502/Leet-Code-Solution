class Solution {
public:
    int solve(int ind , vector<int>& cost,vector<int>&dp){
       if(ind<=1) return 0;
       if(dp[ind]!=-1) return dp[ind]; 
       int jump1 = solve(ind-1,cost,dp) + cost[ind-1] ; 
       int jump2  = solve(ind-2,cost,dp) + cost[ind-2] ; 

       return dp[ind] = min(jump1,jump2);
    }
     int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return solve(n,cost,dp);
    }
};