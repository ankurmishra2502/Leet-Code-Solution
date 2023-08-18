class Solution {
public:
    string removeStars(string s) {
         vector<char> res;
    for(int i=0;i<s.size();i++){
        if(s[i]=='*' && (!res.empty())){
            res.pop_back();
        }
        else if(s[i]!='*'){
            res.push_back(s[i]);
        }
        else{
            continue;
        }
    }
    string result="";
    for(auto x:res){
        result+=x;
    }
    return result;
    }
};