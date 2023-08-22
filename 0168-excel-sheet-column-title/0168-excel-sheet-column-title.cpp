class Solution {
public:
    string convertToTitle(int c) {
        string ans="";
        while(c--){
            char temp= 'A'+ (c%26);
            ans= temp+ans;
            c/=26;
        }
        return ans;
    }
};