class Solution {
public:
    string reorganizeString(string s) {
        map<char,int> mp;
        for(auto x:s){
            mp[x]++;
        }
        string ans="";
        priority_queue<pair<int,char>>pq;
        for(auto x:mp) pq.push({x.second,x.first});
        while(pq.size()>=2){
            auto x= pq.top();
            pq.pop();
            auto y= pq.top();
            pq.pop();
            ans+=x.second;
            x.first--;
            ans+=y.second;
            y.first--;
            if(x.first>0) pq.push(x);
            if(y.first>0) pq.push(y);
        }
        auto x= pq.top();
        if(x.first>1) return "";
        if(pq.size()==1) ans+=x.second;
        return ans;
    }
};