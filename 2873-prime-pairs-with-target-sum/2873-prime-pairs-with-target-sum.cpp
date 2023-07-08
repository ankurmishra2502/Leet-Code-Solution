class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
    int ind=n/2;
    if(n<=2) return ans;
    int i=2;
    while(i<=ind){
        if(check(i) && (check(n-i))){
            ans.push_back({i,n-i});
        }
        i++;
    }
        return ans;
    }
    private:
    bool check(int n){
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++) 
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
};