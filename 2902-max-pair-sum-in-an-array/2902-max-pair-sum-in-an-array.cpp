class Solution {
public:
    bool check(string nums1,string nums2){
        int val1=  *max_element(nums1.begin(),nums1.end());
        int val2=  *max_element(nums2.begin(),nums2.end());
        if(val1==val2) return true;
        else return false;
    }
    int maxSum(vector<int>& nums) {
        int ans= -1;
        for(int i=0;i<nums.size()-1;i++){
           for(int j=i+1;j<nums.size();j++){
               string first=to_string(nums[i]);
               string second=to_string(nums[j]);
               if(check(first,second)){
                   ans= max(ans,nums[i]+nums[j]);
               }

           }
        }
        if(ans!= -1) return ans;
        else return ans;
    }
};