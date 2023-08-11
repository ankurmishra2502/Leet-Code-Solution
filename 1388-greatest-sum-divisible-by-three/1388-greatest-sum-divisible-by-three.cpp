// class Solution {
// public:
//     int solve(vector<int>&nums,int index,int sum,vector<vector<int>> &dp,int check){
//         if(sum%3 ==0) return sum;
//         if(dp[index][check]!=-1) return dp[index][check];
//         if(index==nums.size()) return 0;
//         check= nums[index]%3;
//         int pick= solve(nums,index+1,sum-nums[index],dp,check);
//         int notpick= solve(nums,index+1,sum,dp,check);
//         return dp[index][check]=max(pick,notpick);
//     }
//     int maxSumDivThree(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         int sum=0;
//         for(auto x:nums) sum+=x;
//         vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        
//         cout<<sum;
//         if(sum%3 ==0) return sum;
//         return solve(nums,0,sum,dp,0);
//     }
// };
class Solution {
public:
int ans=0;

    int maxSumDivThree(vector<int>& nums) {
        vector<int>dp(3);
        for(auto a:nums){
            for(int i:vector<int>(dp)){
                dp[(i+a)%3]=max(dp[(i+a)%3],i+a);
            }
        }
       return dp[0];
        
    }
};