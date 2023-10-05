class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int check=nums.size()/3;
        map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<int> ans;
        for(auto x:mp){
            if(x.second>check) ans.push_back(x.first);
        }
        return ans;
    }
};