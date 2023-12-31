class Solution {
public:
    int solve(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!= -1) return dp[i][j];
        int a=INT_MAX;
        if(word1[i]==word2[j]) a= solve(word1,word2,i-1,j-1,dp);
        int r= solve(word1,word2,i-1,j-1,dp)+1;
        int d= solve(word1,word2,i-1,j,dp)+1;
        int in= solve(word1,word2,i,j-1,dp)+1;
        return dp[i][j] = min(a,min(r,min(d,in)));
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(),vector<int>(word2.size(),-1));
        return solve(word1,word2,word1.size()-1,word2.size()-1,dp);
    }
};