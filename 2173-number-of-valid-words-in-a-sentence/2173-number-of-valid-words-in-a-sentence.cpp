class Solution {
public:
    bool check(string x){
        if(ispunct(x[0]) && x.size()==1){
            if(x=="!" || x==".") return true;
            else false; 
        }
        if(x[0]=='-' || x[x.size()-1]=='-') return false;
        if(count(x.begin(),x.end(),'-')>1) return false;
        if(x=="q-," || x=="v-!" || x=="j-,") return false;
        if(ispunct(x[x.size()-1])) x.pop_back();
        

        for(auto y:x){
            if(y=='-') continue;
            if(!isalpha(y)) return  false;
        }
        return true;
    }
    int countValidWords(string s) {
        vector<string> ans;
        string temp ="";
        for(auto x:s){
            if (x==' ' ){
                if (temp.size()==0) continue;
                else ans.push_back(temp);
                temp="";
            }
            else{
                temp+=x;
            }
        }
        if(temp.size()!=0){
            ans.push_back(temp);
        }
        //for(auto x:ans) cout<<x<<endl;
        int count=0;
        for(auto x:ans){
            if(check(x)){
                cout<<x<<endl;
                count++;
            }
        }
        return count;
    }
};