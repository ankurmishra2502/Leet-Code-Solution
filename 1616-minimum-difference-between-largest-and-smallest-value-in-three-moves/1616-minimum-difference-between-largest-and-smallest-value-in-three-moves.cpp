class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4) return 0;
        sort(nums.begin(),nums.end());
        int k=3;
        int diff= nums[nums.size()-k-1]-nums[0];
        int diff1= nums[nums.size()-1]-nums[3];
        int diff2= nums[nums.size()-2]-nums[2];
        int diff3= nums[nums.size()-3]-nums[1];
        return min(diff,min(diff1,min(diff2,diff3)));
    }
};