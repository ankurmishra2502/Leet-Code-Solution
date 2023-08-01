class Solution {
public:
    int trap(vector<int>& h) {
        if(h.size()==0) return 0;
        vector<int> dp(h.size());
        // Maximum value from start to end
        int temp=0;
        for(int i=0;i<h.size();i++){
            temp=max(temp,h[i]);
            dp[i]=temp;
        }
        // Maximum value from end to start
        temp=0;
        for(int i=h.size()-1;i>=0;i--){
            temp=max(temp,h[i]);
            dp[i]=min(dp[i],temp);
        }
        int ans=0;
        for(int i=0;i<h.size();i++){
            ans+=dp[i]-h[i];
        }
        return ans;
    }
};