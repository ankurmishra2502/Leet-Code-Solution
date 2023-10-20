class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        for (int c : costs) {
            if (c > coins) {
                break;
            }
            ++count;
            coins -= c;
        }

        return count;
    }
};