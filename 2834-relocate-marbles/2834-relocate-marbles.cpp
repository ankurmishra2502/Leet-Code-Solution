class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        for(int i=0;i<moveTo.size();i++){
            mp[moveFrom[i]]=0;
            mp[moveTo[i]]++;
        }
        vector<int>ans;
        for(auto x:mp){
            if(x.second>0) ans.push_back(x.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};