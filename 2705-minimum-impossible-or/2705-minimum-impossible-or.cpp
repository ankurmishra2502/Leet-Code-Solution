class Solution {
 public:
  int minImpossibleOR(vector<int>& nums) {
    int ans = 1;
    unordered_set<int> set{nums.begin(), nums.end()};
    while (set.count(ans)) ans <<= 1;

    return ans;
  }
};
