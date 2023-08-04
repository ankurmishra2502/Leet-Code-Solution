class Solution {
public:
    bool find(int left,int right,string &s , unordered_map<string,int>& mp,vector<vector<int>>& dp){
        if(right == s.size()+1)return left == s.size();
        if(dp[left][right]!=-1)return dp[left][right];
        string temp (s.begin()+left,s.begin()+right);
        bool flag = false;
        if(mp.find(temp)!=mp.end())  flag = find(right,right+1,s,mp,dp);
        if(flag == true) return dp[left][right] = 1;
        flag = find(left,right+1,s,mp,dp);
        return dp[left][right] = flag;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> mp;
        for(auto it:wordDict) mp[it]++;
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        find(0,0,s,mp,dp); 
        return dp[0][0];
    }
};