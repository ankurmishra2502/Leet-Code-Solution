class Solution {
public:
struct cmp {
    bool operator() (pair<int, string> a, pair<int, string> b) {
        if(a.first == b.first)
            return a.second > b.second;
        else
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp;
        for(auto x:words) mp[x]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
        for(auto x:mp){
            pq.push({x.second,x.first});
        }
        vector<string> vec;
        while(k--){
            vec.push_back(pq.top().second);
            pq.pop();
        }
       // sort(vec.begin(),vec.end(),cmp);
        return vec;
    }
};