class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> bps=h;
        sort(bps.begin(),bps.end());
        int i=0;
        int choro=0;
        for(auto x:bps){
            if(x!=h[i]) choro++;
            i++;
        }
        return choro;
    }
};