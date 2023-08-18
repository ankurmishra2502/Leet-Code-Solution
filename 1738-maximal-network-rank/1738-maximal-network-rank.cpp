class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto x:roads){
            mp[x[0]].insert(x[1]);
            mp[x[1]].insert(x[0]);
        }
        int max_val=0;
        for(int i=0;i<n;i++){
            for(int j= i+1;j<n;j++){
                int temp= mp[i].size() + mp[j].size();
                if(mp[i].find(j)!= mp[i].end()) temp--;
                max_val= max(max_val,temp);
            }
        }
        // for(auto x:mp) cout<<x.first<<" "<<x.second<<endl;
        return max_val;
    }
};