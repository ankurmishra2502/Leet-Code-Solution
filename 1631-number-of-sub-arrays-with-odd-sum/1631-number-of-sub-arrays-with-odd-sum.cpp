// class Solution {
// public:
//     int solve(vector<int> &nums,int idx,int sum,int flag){
//         if(flag==1 && idx>0 && sum>0){
//             return sum%2;
//         }
//         if(idx==nums.size()) return (sum)%2;
//         if(flag==1) sum=0;
//         return solve(nums,idx+1,sum+nums[idx],0)+solve(nums,idx+1,sum,1);
//     }
//     int numOfSubarrays(vector<int>& arr) {
//         return solve(arr,0,0,0);
//     }
// };
class Solution {
public:
    int mod = 1000000007;
    int numOfSubarrays(vector<int>& arr) {
    int ans = 0;
    int even = 0;
    int odd = 0;
    for(int i : arr){
        if(i&1){
            int temp=even;
            even=odd;
            odd= temp+1;
        }
        else{
            even++;
        }
        ans= (ans+odd)%mod;
    }
    return ans;
    }
};