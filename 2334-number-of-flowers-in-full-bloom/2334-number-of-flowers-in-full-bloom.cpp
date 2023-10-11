class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        int N = people.size();

        vector<pair<int,int>>v;

        for(int i = 0; i < N; i++) {
            v.push_back({people[i], i});
        }

        sort(v.begin(), v.end());
        sort(flowers.begin(), flowers.end());


        int M = flowers.size();

        priority_queue<int, vector<int>, greater<int>>pq;
        vector<int>ans(N);

        int j = 0;


        for(int i = 0; i < N; i++) {
            
            int t = v[i].first;
            int idx = v[i].second;

            while(j < M && flowers[j][0] <= t) {
                pq.push(flowers[j][1]);
                j++;
            }

            while(!pq.empty() && pq.top() < t) {
                pq.pop();
            }


            ans[idx] = pq.size();

        }
        
        return ans;

    }
};