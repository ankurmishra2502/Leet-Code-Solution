class Solution {
public:
void solve(int i,string d,string m[],string s,vector<string>& a){
    if(i==d.size()){
        a.push_back(s);
        return;
    }
    int digit=d[i]-'0';
    string val= m[digit];
    for(int j=0;j<val.size();j++){
        s.push_back(val[j]);
        solve(i+1,d,m,s,a);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string sol;
        if(digits.size()==0) return ans;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,map,sol,ans);
        return ans;
    }
};