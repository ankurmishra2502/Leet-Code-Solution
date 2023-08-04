// TLE
// class Solution {
// public:
//     void solve(vector<int> &nums,int k,int index,int sum,int &max_val){
//         if(index==nums.size()-1){
//             max_val=max(max_val,sum);
//             return;
//         }
//         for(int i=1;(i<=k && (i+index)<nums.size());i++){
//             solve(nums,k,i+index,sum+nums[i+index],max_val);
//         }
//     }
//     int maxResult(vector<int>& nums, int k) {
//         int max_val=INT_MIN;
//         solve(nums,k,0,nums[0],max_val);
//         return max_val;
//     }
// };


class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        multiset<int> s;
        s.insert(nums[0]);
        dp[0] = nums[0];
       for (int i = 1; i < n; i++)
       {
           if(i > k) s.erase(s.find(dp[i-k-1]));
           dp[i] = *s.rbegin() + nums[i];
           s.insert(dp[i]);
       }

        return dp.back();
    }
};