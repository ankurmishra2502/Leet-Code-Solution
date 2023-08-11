class Solution {
public:
    int solve(vector<int>&coins,int amount,int index,vector<vector<int>>&dp){
        if(index==0){
            if(amount%coins[index] ==0) return 1;
            else {
                return 0;
            }
        }
        if(dp[index][amount]!= -1) return dp[index][amount];
        int Take=0;
        if(amount>=coins[index]) Take= solve(coins,amount-coins[index],index,dp);
        int notTake=solve(coins,amount,index-1,dp);
        return dp[index][amount]=Take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins,amount,coins.size()-1,dp);
    }
};