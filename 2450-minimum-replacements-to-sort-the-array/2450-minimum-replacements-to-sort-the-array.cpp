class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    long long ans = 0;
    int max = nums.back();
    for (int i = nums.size() - 2; i >= 0; --i) {
      int op = (nums[i] - 1) / max;
      ans += op;
      max = nums[i] / (op + 1);
    }

    return ans;
  }
};
