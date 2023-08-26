// class Solution {
// public:
//     int solve(vector<vector<int>>&p,int ind,int prev,vector<int>&dp){
//         if(ind>=p.size()) return 0;
//         if(dp[ind]!=-1) return dp[ind];
//         int pick= 0;
//         if(prev<p[ind][0]){
//             pick=1+solve(p,ind+1,p[ind][1],dp);
//         }
//         int notPick= solve(p,ind+1,prev,dp);
//         return dp[ind]=max(pick,notPick);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         sort(pairs.begin(),pairs.end());
//         int prev= INT_MIN;
//         vector<int> dp(pairs.size()+1,-1);
//        return solve(pairs,0,prev,dp);
//     }
// };
class Solution {
public:
    int solve(vector<vector<int>>&p,int ind,int prev,vector<int>&dp){
        if(ind>=p.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int i=0;
        for(i = ind + 1; i < p.size();i++) {
            if(p[i][0] > p[ind][1]) {
                break;
            }
        }
        int pick=1+solve(p,i,p[ind][1],dp);
        int notPick= solve(p,ind+1,prev,dp);
        return dp[ind]=max(pick,notPick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int prev= INT_MIN;
        vector<int> dp(pairs.size()+1,-1);
       return solve(pairs,0,prev,dp);
    }
};