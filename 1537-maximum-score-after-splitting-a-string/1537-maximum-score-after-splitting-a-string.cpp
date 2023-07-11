class Solution {
public:
    int solve(string s,int start,int end,char target){
        string temp= s.substr(start,end+1);
        int cnt= count(temp.begin(),temp.end(),target);
        return cnt;
    }
    int maxScore(string s) {
        int i=0;
        int n=s.size()-1;
        int min_val=INT_MIN;
        while(i!=n){
            int patelji=solve(s,0,i,'0')+solve(s,i+1,n,'1');
            min_val=max(min_val,patelji);
            i++;
        }
        return min_val;
    }
};