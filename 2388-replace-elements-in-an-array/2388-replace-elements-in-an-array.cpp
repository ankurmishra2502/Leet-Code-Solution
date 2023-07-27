class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& op) {
        unordered_map<int,int> mp;
        int i=0;
        for(auto x: nums){
            mp[x]=i;
            i++;
        }
        for(auto x:op){
            nums[mp[x[0]]]= x[1];
            mp[x[1]]=mp[x[0]];
        }
        return nums;
    }
};