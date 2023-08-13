class Solution {
public:
   bool solve(vector<int> &nums,int ind){
      int n=nums.size();
      if(ind==-1){
          return true;
      }
      bool ans=false;
      if(ind-1>=0){
        if(nums[ind]==nums[ind-1]){
            ans=(ans || solve(nums,ind-2));
        }
      }
      if(ind-2>=0){
         if(nums[ind]==nums[ind-1] && nums[ind-1]==nums[ind-2]){
             ans=(ans  || solve(nums,ind-3));
         }
         if(nums[ind]==nums[ind-1]+1 && nums[ind-1]==nums[ind-2]+1){
             ans=(ans || solve(nums,ind-3));
         }
      }
      return ans;
   }

    bool validPartition(vector<int>& nums) {
       int n=nums.size();
       return solve(nums,n-1); 
    }
};