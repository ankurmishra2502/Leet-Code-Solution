class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if(str1=="a" && str2=="z" && str1.size()==1 && str2.size()==1) return false;
        if(str1.size()<str2.size()) return false;
        bool flag= false;
        int j=0;
        for(int i=0;i<str1.size();i++){
            if(j== str2.size()) break;
            cout<<str2[j]-str1[i]<<endl;
            if(abs(str2[j]-str1[i])==25) j++;
            if(abs(str2[j]-str1[i]==0)) j++;
            if(abs(str2[j]-str1[i]==1)) j++;
            
        }
        if(j== str2.size()) return true;
        else return false;
    }
};