class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> temp;
        string ans;
        int max_length=0;
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                temp.push_back(ans);
                ans="";
                max_length=max(max_length,x);
                x=0;
            }
            else{
                x++;
                ans+=s[i];
            }
        }
        temp.push_back(ans);
        int j= ans.size();
        max_length= max(max_length,j);
        vector<string> final_ans;
        for(int i=0;i<max_length;i++){
            string t;
            for(auto x:temp){
                if(i>=x.size())t+=" ";
                else t+=x[i];
            }
            for(int i=t.size()-1;i>=0;i--){
                if(t[i]==' ') t.pop_back();
                else break;
            }
            final_ans.push_back(t);
        }
        return final_ans;
    }
};