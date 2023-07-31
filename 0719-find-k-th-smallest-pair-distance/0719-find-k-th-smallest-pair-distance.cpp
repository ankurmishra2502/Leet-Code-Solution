class Solution {
public:
    int solve(vector<int>& nums, int dis) {
        int count=0, low=0, high=1;
        while(high<nums.size()) {
            while(nums[high]-nums[low] > dis) low++;
            count += high-low;
            high++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0, right=nums[nums.size()-1]-nums[0];
        while(left<right) {
            int mid=left+(right-left)/2;
            if(solve(nums, mid) < k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};