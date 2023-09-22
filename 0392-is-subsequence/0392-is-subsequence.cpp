class Solution {
public:
    bool isSubsequence(string s, string t) {
        int len_s=s.length();
        int len_t=t.length();
        int i=0,j=0;
        while(i<len_s && j<len_t){
            if(t[j]==s[i]){
                i++;
                j++;
            }
            else{
                j++;
            }
            
        }
        if(i==len_s) return true;
        return false;
    }
};