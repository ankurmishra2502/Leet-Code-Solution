class Solution {
public:
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        if(a.first<b.first) return true;
        if(a.first==b.first and a.second<b.second) return true;
        return false;
    }
    int solve(int low,map<int,int>&dp){
        if(low==1){
            return 0;
        }
        if(dp.find(low)!= dp.end()) return dp[low];
        int even=0,odd=0;
        if(low%2==0) even=1+ solve(low/2,dp);
        else odd=1+ solve(3*low+1,dp);
        return dp[low]= even+odd;
    }
    int getKth(int lo, int hi, int k) {
        map<int,int> dp;
        vector<pair<int,int>> pq;
        for(int i=lo;i<=hi;i++){
            int count=solve(i,dp);
            pq.push_back({count,i});
        }
        
        sort(pq.begin(),pq.end(),cmp);
        
        return pq[k-1].second;
    }
};