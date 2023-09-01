class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> dp(10001);
    for (int x : nums)
      dp[x] += x;

    int prev1 = 0;
    int prev2 = 0;
    for (int x : dp) {
      int temp = max(prev1, prev2 + x);
      prev2 = prev1;
      prev1 = temp;
    }

    return prev1;
  }
};
