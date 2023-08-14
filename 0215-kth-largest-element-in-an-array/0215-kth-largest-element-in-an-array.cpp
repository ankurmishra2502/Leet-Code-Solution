class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         priority_queue<int> pq;
    for(auto x: nums){
        pq.push(x);
    }
    int max_val=0;
    for(int i=0;i<k;i++){
        max_val=pq.top();
        pq.pop();
    }
    return max_val;
    }
};