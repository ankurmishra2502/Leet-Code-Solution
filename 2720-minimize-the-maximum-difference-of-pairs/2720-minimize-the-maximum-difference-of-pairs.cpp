class Solution {
public:
    bool solve(vector<int> nums,int mid,int p){
        int cnt=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=mid){
                cnt+=1;
                i+=1;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0;
        int high= nums[nums.size()-1]-nums[0];
        while(low<high){
            int mid= (low+high)/2;
            if(solve(nums,mid,p)){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};