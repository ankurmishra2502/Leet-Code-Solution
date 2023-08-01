class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(n,k,1,temp,ans);
        return ans;
    }
    private:
    void solve(int n,int k,int start,vector<int> &temp,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(start == n+1) return;
        solve(n,k,start+1,temp,ans);
        temp.push_back(start);
        solve(n,k-1,start+1,temp,ans);
        temp.pop_back();
    } 
}; 