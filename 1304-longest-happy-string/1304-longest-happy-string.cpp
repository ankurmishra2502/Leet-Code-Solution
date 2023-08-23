class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        int counter=2;
        string ans="";
        while(pq.size()>1){
            auto y= pq.top();
            pq.pop();
            auto x= pq.top();
            pq.pop();
            if(y.first>=2){
                ans+=y.second;
                ans+=y.second;
                y.first-=2;
            }
            else{
                ans+=y.second;
                y.first--;
            }
            if(x.first>=2 && x.first>= y.first){
                ans+=x.second;
                ans+=x.second;
                x.first-=2;
            }
            else{
                ans+=x.second;
                x.first--;
            }
            if(x.first>0) pq.push(x);
            if(y.first>0) pq.push(y);
        }
       if(pq.size()==0) return ans;
       else{
           auto x= pq.top();
           if(x.first>2) x.first=2;
           while(x.first--) ans+=x.second;
       }
       return ans;
    }
};