class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int>mp;
        for(auto x:roads){
            mp[x[0]]++;
            mp[x[1]]++;
        }
        priority_queue<pair<int,int>>pq;
        int index=0;
        for(auto x:mp){
            //int sum= accumulate(x.second.begin(),x.second.end(),0);
            pq.push({x.second,x.first});
        }
        vector<int> ans(n);
        int i=n;
        while(!pq.empty()){
            auto val= pq.top();
            ans[val.second]=i;
            i--;
            pq.pop();
        }
        for(auto x:ans) cout<<x<<" ";
        long long max_val=0;
        for(auto x:roads){
            max_val+=(ans[x[0]]+ans[x[1]]);
        }
        return max_val;
    }
};