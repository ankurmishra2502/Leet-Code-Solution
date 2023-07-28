class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp;
        vector<int> ans;
        if(p.size()>s.size()) return ans;

        for(int i=0;i<p.size();i++){
            mp1[s[i]]++;
            mp[p[i]]++;
        }
        if(mp1==mp) ans.push_back(0);

        for(int i=p.size();i<s.size();i++){
            
            mp1[s[i]]++;
            mp1[s[i-p.size()]]--;
             if(mp1[s[i-p.size()]] <= 0){
                mp1.erase(s[i-p.size()]);
            }
            
            if(mp1==mp) ans.push_back(i+1-p.size());

        }

        return ans;
    }
};