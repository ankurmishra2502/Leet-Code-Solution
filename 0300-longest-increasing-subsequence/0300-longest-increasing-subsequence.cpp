class Solution {
public:
    int solve(vector<int>&nums,int index,int prev, vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index][prev+1]!= -1) return dp[index][prev+1];
        int pick=0;
        if(prev== -1 || nums[prev]<nums[index]){
            pick= 1+ solve(nums,index+1,index,dp);
        }
        int notPick= solve(nums,index+1,prev,dp);
        return dp[index][prev+1]=max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev= -1;
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+2,-1));
        return solve(nums,0,prev,dp);
    }
};