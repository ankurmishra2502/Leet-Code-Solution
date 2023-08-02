// TLE

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> temp;
//         for(int i=0;i<k;i++){
//             temp.push_back(nums[i]);
//         }
//         vector<int> ans;
//         int max_ele= *max_element(temp.begin(),temp.end());
//         ans.push_back(max_ele);
//         int start=0;
//         int end=k;
//         while(end<nums.size()){
//             temp.erase(temp.begin());
//             temp.push_back(nums[end]);
//             int val=*max_element(temp.begin(),temp.end());
//             ans.push_back(val);
//             start++;
//             end++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for( int i=0; i<k; i++ ){
            while(!dq.empty() && nums[i]>=nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for( int j=k; j<nums.size(); j++ ){
            while(!dq.empty() && dq.front()<=j-k)
                dq.pop_front();
            while(!dq.empty() && nums[j]>=nums[dq.back()])
                dq.pop_back();

            dq.push_back(j);
            ans.push_back(nums[dq.front()]); 
        }
        return ans;
    }
};