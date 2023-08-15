class Solution {
public:
  static bool cmp(vector<int>& a1, vector<int> &a2) {
        return a1[1] < a2[1];
    }
    bool carPooling(vector<vector<int>>& trip, int capacity) {
        sort(trip.begin(),trip.end(),cmp);
        int temp=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto x:trip){
            for(auto y:x){
                cout<<y<<" ";
            }
            cout<<endl;
        }
        for(auto x:trip){
            int people= x[0];
            int start= x[1];
            int end= x[2];
            while(!pq.empty() && start>= pq.top().first){
                temp-=pq.top().second;
                pq.pop();
            }
            if(temp+people > capacity){
                return false;
            }
            temp+=people;
            pq.push({end,people});
        }
        return true;
    }
};