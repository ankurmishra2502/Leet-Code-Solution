class Solution {
 public:
  vector<int> closestDivisors(int num) {
    vector<int> val={num+1,num+2};
    for (int x = sqrt(num + 2); x > 0; --x){
        for (int y : val){
            if (y % x == 0)
            return {x, y / x};
        }
    }
    return {};
  }
};
