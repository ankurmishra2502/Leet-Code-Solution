class Solution {
public:
    bool isPowerOfFour(int n) {
        int temp=n;
        int power=0;
        if(temp%2==0){
            while(temp>1){
                temp=temp/4;
                power++;
            }
        }
        if(n!=pow(4,power)) return false;
        return true;
    }
};