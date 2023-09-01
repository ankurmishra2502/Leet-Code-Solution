class Solution {
public:
    long long numberOfWeeks(vector<int>& mil) {
        long long sum=0;
        int max_val= INT_MIN;
        for(auto x:mil){
            sum+=x;
            max_val= max(max_val,x);
        }
        long long int rem= sum-max_val;
        if(rem>= max_val-1) return sum;
        else return 2*rem+1;
    }
};