class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            bool flag=false;
            int temp=0;
            int cnt=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]-nums[j-1]==cnt){
                    flag=true;
                    cnt*=-1;
                    temp++;
                }
                else{
                    break; 
                }
            }
            if(flag==true)
            ans=max(ans,temp+1);
        }
        return ans;
    }
};