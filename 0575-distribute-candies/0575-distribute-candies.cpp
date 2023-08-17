class Solution {
public:
    int distributeCandies(vector<int>& c) {
        map<int,int> mp;
        for(auto x:c){
            mp[x]++;
        }

        if(mp.size()>c.size()/2) return c.size()/2;
        else return mp.size();
    }
};