class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int ans = INT_MIN;
    int temp = values[0];

    for (int i=1;i<values.size();i++) {
      ans = max(ans,temp+values[i]-i);
      temp = max(temp,values[i]+i);
    }

    return ans;
  }
};
