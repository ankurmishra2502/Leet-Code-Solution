class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long total=0;
        int index=0;
        int count=0;
        while(total<n){
            if(index<nums.size() && nums[index]<=total+1){
                total+=nums[index];
                index++;
            }
            else{
                count++;
                total+=(total+1);
            }
        }
        return count;
    }
};