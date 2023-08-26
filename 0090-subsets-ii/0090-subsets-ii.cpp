class Solution {
 public:
  set<vector<int>>s;

  void solve(vector<int>& nums, int ind, vector<int>& path,vector<vector<int>>& ans) {
    if(ind==nums.size()){
      if(s.find(path)==s.end()){
        ans.push_back(path);
        s.insert(path);
      }
      return;
    }
    path.push_back(nums[ind]);
    solve(nums,ind+1,path,ans);
    path.pop_back();
    solve(nums,ind+1,path,ans);
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    vector<int> path;
    solve(nums, 0, path, ans);
    return ans;
  }
 
};
