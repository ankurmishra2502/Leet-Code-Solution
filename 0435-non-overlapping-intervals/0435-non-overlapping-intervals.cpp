class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){
          return a[1]<b[1];
      }
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
         sort(nums.begin(),nums.end(),cmp);
  int cnt=0;
  int prev=nums[0][1];
  for(int i=1;i<nums.size();i++){
    if(prev>nums[i][0]) cnt++;
    else prev=nums[i][1];
  }
  return cnt;
  
    }
};