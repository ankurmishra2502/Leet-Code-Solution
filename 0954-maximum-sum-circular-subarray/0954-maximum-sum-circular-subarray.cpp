class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       int check= *max_element(nums.begin(),nums.end());
       if(check<0) return check;
       int curr=0;
       int ans1=INT_MIN;
       for(int i=0;i<nums.size();i++){
           curr+=nums[i];
           ans1=max(ans1,curr);
           if(curr<0) curr=0;
       }
       curr=0;
       int ans2=INT_MAX;
       for(int i=0;i<nums.size();i++){
           curr+=nums[i];
           ans2=min(ans2,curr);
           if(curr>0) curr=0;
       }
       int sum= accumulate(nums.begin(),nums.end(),0);
       return max(ans1,sum-ans2);
    }
};