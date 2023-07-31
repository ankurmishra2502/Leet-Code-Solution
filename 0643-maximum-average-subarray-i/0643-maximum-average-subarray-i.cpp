class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg= INT_MIN;
        double avg=0;
        for(int i=0;i<k;i++){
            avg+=nums[i];
        }
        avg= avg/k;
        int start=0;
        int end=k;
        max_avg= max(max_avg,avg);
        while(end<nums.size()){
            avg-=(double)nums[start]/k;
            avg+=(double)nums[end]/k;
            max_avg= max(max_avg,avg);
            start++;
            end++;
        }
        return max_avg;
    }
};