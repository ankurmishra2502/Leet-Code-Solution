class Solution {
public:
    int minDeletions(string s) {
        map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        vector<int> temp;
        int count=0;
        for(auto x:mp) temp.push_back(x.second);
        sort(temp.begin(),temp.end(),greater<int>());
        
        for(int i=1;i<temp.size();i++){
            while(temp[i]>=temp[i-1] && temp[i]>0)
            {
                temp[i]--;
                count++;
            }
        }
        return count;
    }
};