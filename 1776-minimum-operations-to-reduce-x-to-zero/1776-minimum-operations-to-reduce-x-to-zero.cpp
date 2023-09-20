class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < x) return -1; 
        if(sum == x) return nums.size();
        int target = sum - x;
        int maxSize = 0; 
        int currSum = 0;
        int start = 0;
        for(int i = 0; i<nums.size(); i++){
            currSum += nums[i];
            while(currSum > target){
                currSum -= nums[start];
                start++;
            }
            if(currSum == target){
                maxSize = max(maxSize, i-start+1);
            }
        }
        if(maxSize == 0){
            return -1;
        }
        else {
            return nums.size() - maxSize; 
        }
    }
};