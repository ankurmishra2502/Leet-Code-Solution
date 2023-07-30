// TLE
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         for(int i=0; i<n; i++){
//             int product = 1;
//             for(int j=0; j<n; j++){
//                 if(i == j) continue;
//                 product *= nums[j];
//             }
//             ans.push_back(product);
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int product = 1;
        for(int i = 0; i< nums.size(); i++) {
            ans[i] = product;
            product *= nums[i];
        }
        product = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            ans[i] *= product;
            product *= nums[i];
        }
        return ans;
    }
};