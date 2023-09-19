
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev=-1;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(prev==nums[i]) count=nums[i];
            prev=nums[i];
        }
        return count;
    }
};