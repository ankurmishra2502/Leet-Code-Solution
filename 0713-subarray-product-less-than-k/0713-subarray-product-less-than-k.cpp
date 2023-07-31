class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count=0;
        int j=0;
        int product=1;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            while(product>= k && j<nums.size()){
                product= product/nums[j];
                j++;
            }
            if(product<k) count+= i- j +1;
        }
        return count;
    }
};