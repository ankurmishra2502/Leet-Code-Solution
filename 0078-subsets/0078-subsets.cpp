class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>&nums,int index,vector<int> &path,vector<vector<int>>&ans){
        if(index==nums.size()){
            if(s.find(path)==s.end()){
                ans.push_back(path);
                s.insert(path);
            }
            return;
        }
        path.push_back(nums[index]);
        solve(nums,index+1,path,ans);
        path.pop_back();
        solve(nums,index+1,path,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(nums,0,path,ans);
        return ans;
    }
};