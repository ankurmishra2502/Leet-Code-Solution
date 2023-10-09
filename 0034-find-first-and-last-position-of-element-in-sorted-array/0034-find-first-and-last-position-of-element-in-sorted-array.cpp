// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         if(nums.size()==0) return {-1,-1};
//         if(nums.size()==1 && nums[0]==target) return {0,0};
//         if(nums.size()==1 && nums[0]!=target) return {-1,-1};
        
//         int l=0;
//         int r=nums.size()-1;
//         int first,last;
//         int lflag=0;
//         int rflag=0;
//         while(l<nums.size() && r>=0){
//             if(nums[l]==target && lflag==0){
//                 lflag=1;
//                 first=l;
//             }
//             if(nums[r]==target && rflag==0){
//                 rflag=1;
//                 last=r;
//             }
//             if(lflag==0){
//                 l++;
//             }
//             if(rflag==0){
//                 r--;
//             }
            
//             if(lflag==1 && rflag==1 ) break;
            
//         }
//         if(lflag!=0 && rflag!=0) return {first,last};
//         return {-1,-1};
        
//     }
// };
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int l = lower_bound(begin(nums), end(nums), target) - begin(nums);
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r = upper_bound(begin(nums), end(nums), target) - begin(nums) - 1;
    return {l, r};
  }
};
