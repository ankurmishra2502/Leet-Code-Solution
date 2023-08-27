class Solution {
public:
    bool solve(vector<int>&stones,int index,unordered_map<int,int>&mp,int step,vector<vector<int>>&dp){
        if(index>=stones.size()) return false;
        if(index==stones.size()-1) return true;
        if(dp[index][step]!= -1) return dp[index][step];
        bool left=false,center=false,right=false;
        if(step>1 && mp.count(stones[index]+step-1)) left= solve(stones,mp[stones[index]+step-1],mp,step-1,dp);
        if(step>0 && mp.count(stones[index]+step)) center= solve(stones,mp[stones[index]+step],mp,step,dp);
        if(mp.count(stones[index]+step+1)) right= solve(stones,mp[stones[index]+step+1],mp,step+1,dp);
        return dp[index][step]=(left or center or right);
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int,int>mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1));
        return solve(stones,0,mp,0,dp);
    }
};