class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int sum=0;
        priority_queue<long long int> pq(nums.begin(),nums.end());
        while(k>0){
            long long int x= pq.top();
            pq.pop();
            sum+=x;
            if(ceil(x/3.0)>0)
            pq.push(ceil(x/3.0));
            k--;
        }
        return sum;
    }
};