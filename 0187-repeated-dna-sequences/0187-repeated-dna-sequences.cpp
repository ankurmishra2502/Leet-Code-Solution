class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> mp;
        string ans;
        for(int i=0;i<10;i++){
            ans+=s[i];
        }   
        mp[ans]++;
        for(int i=10;i<s.size();i++){
            ans.erase(ans.begin());
            ans+=s[i];
            mp[ans]++;
        }
        vector<string> val;
        for(auto x:mp) if(x.second>1) val.push_back(x.first);
        return val;
    }
};