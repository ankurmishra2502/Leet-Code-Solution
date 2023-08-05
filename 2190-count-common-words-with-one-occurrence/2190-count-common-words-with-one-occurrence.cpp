class Solution {
public:
    int countWords(vector<string>& word1, vector<string>& word2) {
        unordered_map<string,int> mp;
        unordered_map<string,int> mp_1;
        for(auto x:word1){
            mp[x]++;
        }
        for(auto x:word2){
            mp_1[x]++;
        }
        int count=0;
        for(auto x:word1){
            if(mp[x]==1 && mp_1[x]==1) count++;
        }
        return count;
    }
};