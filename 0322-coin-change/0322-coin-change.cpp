class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
         int ans=solve(coins,coins.size()-1,amount,dp);
        return (ans== 1e9) ? -1 : ans;
    }
    private:
     int solve(vector<int> &coins,int ind,int amount,vector<vector<int>> &dp){
       if(!ind){
			if(amount%coins[ind]==0) return amount/coins[ind];
			else return 1e9;
		}
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notPick= solve(coins,ind-1,amount,dp);
        int pick=1e9;
        if(amount>=coins[ind]){
            pick =1+ solve(coins,ind,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(pick,notPick);
    }
};