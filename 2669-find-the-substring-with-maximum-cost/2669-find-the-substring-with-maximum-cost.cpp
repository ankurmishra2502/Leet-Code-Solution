class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char,int>mp;
        int i=0;
        for(auto x:chars){
            mp[x]=vals[i];
            i++;
        }  
        int max_val=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])!=mp.end()){
                curr_sum+=mp[s[i]];
            }
            else{
                curr_sum+=(int(s[i])-96);
            }
            if(curr_sum<0) curr_sum=0;
            max_val= max(max_val,curr_sum);
        }
        return max_val;
    }
};