class Solution {
public:
    double angleClock(int hour, int minutes) {
        double min= (5.5)*minutes;
        hour%=12;
        double hrs= 30*hour;
        double ans=abs(min-hrs);
        if(ans>180) return double(360-ans);
        else return ans;
    }
};