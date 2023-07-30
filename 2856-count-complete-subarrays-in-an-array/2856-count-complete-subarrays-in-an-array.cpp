class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>mp(nums.begin(),nums.end());
        int n=nums.size();
        if(mp.size()==1) return (n*(n+1))/2;
        int count=0;
        for(int i=0;i<nums.size();i++){
            unordered_set<int>temp;
            temp.insert(nums[i]);
            for(int j=i+1;j<nums.size();j++){
                temp.insert(nums[j]);
                if(temp.size()==mp.size()) count++;
            }
        }
        return count;
    }
};