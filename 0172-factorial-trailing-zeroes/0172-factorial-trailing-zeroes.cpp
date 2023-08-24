class Solution {
public:
    int solve(int x){
        if(x<5) return 0;
        return (x/5)+ solve(x/5);
    }
    int trailingZeroes(int n) {
        return solve(n);
    }
};