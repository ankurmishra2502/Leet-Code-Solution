class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int cnt= target.size();
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if(cnt==0) break;
            if(count(target.begin(),target.end(),i)==1){
                cnt--;
                ans.push_back("Push");
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};