class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(auto x:tasks){
            mp[x]++;
        }
        int count=0;
        for(auto x:mp){
            if(x.second<2) return -1;
            if(x.second%3==0){
                count+= x.second/3;
            }
            else{
                count+= x.second/3 + 1;
            }
        }
        return count;
    }
};