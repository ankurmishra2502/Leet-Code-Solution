class Solution {
public:
    bool solve(vector<int>&nums,int indx,int size,vector<int> &dp){
        if(indx==size-1) return true;
        if(indx>size-1) return false;
        if(dp[indx]!= -1) return dp[indx];
        for(int i=1;i<=nums[indx];i++){
            if(solve(nums,indx+i,size,dp)) return dp[indx]=true;
        }
        return dp[indx]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
       return  solve(nums,0,nums.size(),dp);
    }
};