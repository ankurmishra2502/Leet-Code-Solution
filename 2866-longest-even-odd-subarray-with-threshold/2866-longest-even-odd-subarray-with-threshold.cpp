class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0, curr = 1, n = nums.size();
        if (n == 0) 
            return n;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0 && ans == 0 && nums[i] <= threshold) 
                ans = 1; 
            for (int j = i + 1; j < n; j++) {
                
                if (nums[i] % 2 == 0 && nums[j] % 2 != nums[j - 1] % 2 && nums[j] <= threshold && nums[i] <= threshold )  {
                    curr++;
                    ans = max(ans, curr);
                } else 
                    break;
            }
            curr = 1;
        }
        
        return ans;
    }
};