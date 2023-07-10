class Solution {
public:
    int maxAbsValExpr(const vector<int>& arr1, const vector<int>& arr2) {
        int maxAbs = 0;
        const vector<int> signs{-1, 1};
        for (const int sign1 : signs) {
            for (const int sign2 : signs) {
                for (const int signInd : signs) {
                    int maxVal = INT_MIN;
                    int minVal = INT_MAX;
                    for (int i = 0; i < arr1.size(); ++i) {
                        const int sum = sign1 * arr1[i] + sign2 * arr2[i] + signInd * i;
                        maxVal = max(maxVal, sum);
                        minVal = min(minVal, sum);
                    }
                    maxAbs = max(maxAbs, maxVal - minVal);
                }
            }
        }
        return maxAbs;
    }
};