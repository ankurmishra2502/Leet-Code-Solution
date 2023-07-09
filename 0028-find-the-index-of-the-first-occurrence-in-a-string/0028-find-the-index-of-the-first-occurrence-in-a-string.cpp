class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        if(n==0) return 0;
        if(haystack.size() < needle.size())
            return -1;
        int j=0;
        for(int i=0;i<m;i++){
            if(haystack[i]==needle[j]){
                j++;
                for(int k=i+1;k<m;k++){
                    
                    if(haystack[k]==needle[j]) j++;
                    else break;
                }
                if (j==n) return i;
                else j=0;
            }
        }
        return -1;
    }
};