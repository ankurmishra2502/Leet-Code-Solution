class Solution {
public:
    int  solve(int start,int end,vector<int>&piles,vector<vector<int>>&dp){
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int From_start=0, From_end=0;
        From_start= piles[start]-solve(start+1,end,piles,dp);
        From_end= piles[end]-solve(start,end-1,piles,dp);
        return dp[start][end]= max(From_start,From_end);
    }
    bool stoneGame(vector<int>& piles) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(piles.size()+1,-1));
        if(solve(0,piles.size()-1,piles,dp)>0) return true;
        else return false;
    }
};