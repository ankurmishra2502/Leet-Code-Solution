class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s =to_string(n);
        int k= s.size();
        int index= s.size()-1;
        while(index-1>=0){
            if(s[index]<s[index-1]) break;
            index--;
        }
        if(index==0) return (int)stoi(s);
        s[index-1]=s[index-1]-1;
        while(index<k){
            s[index]='9';
            index++;
        }
        return monotoneIncreasingDigits((int)stoi(s));
    }
};