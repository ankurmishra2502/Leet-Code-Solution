class Solution {
public:
    int minSteps(int n) {
		int ans = 0, i = 2;
        while(n!=1){
            if(n%i == 0){
                n = n/i;
                ans += i;
            }
            else
                i++;
        }
        
        return ans;
    }
};
