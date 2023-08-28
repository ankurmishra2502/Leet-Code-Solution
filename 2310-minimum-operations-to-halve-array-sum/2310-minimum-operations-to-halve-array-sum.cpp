class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum= 0;
        
        for(auto x:nums){
            sum+=x;
            pq.push(x);
        }
        double half= sum/2;
        int operation=0;
        while(sum>half){
            operation++;
            double val= pq.top();
            pq.pop();
            val/=2;
            sum-=val;
            pq.push(val);
        }
        return operation;
    }
};