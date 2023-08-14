class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
        pair<double, vector<int>>,
        vector<pair<double, vector<int>>>,
        greater<pair<double, vector<int>>>>
    pq;
        for(auto x:points){
            double dist= (pow(x[0],2))+(pow(x[1],2));
            dist= sqrt(dist);
            pq.push({dist,x});
        }
        vector<vector<int>> ans;
        while(k--){
            auto val= pq.top();
            ans.push_back(val.second);
            pq.pop();
        }
        return ans;
    }
};