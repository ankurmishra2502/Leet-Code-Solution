class Solution {
public:
    int beautySum(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            map<char,int> mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int min_ele= INT_MAX;
                int max_ele= INT_MIN;
                for(auto x:mp){
                    max_ele= max(max_ele,x.second);
                    min_ele= min(min_ele,x.second);
                }
                ans+=(max_ele-min_ele);
            }
        }
        return ans;
    }
   
};