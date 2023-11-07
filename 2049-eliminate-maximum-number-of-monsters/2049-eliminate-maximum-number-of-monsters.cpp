class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> monsters_time(n+1, 0);
        #pragma unroll
        for(int i=0; i<n; i++){
            int t=ceil((double)dist[i]/speed[i]);
            if (t>n) t=n;
            monsters_time[t]++;
        }
        int shot=1, monsters=0;
        #pragma unroll
        for (; shot<=n; shot++){
            monsters+=monsters_time[shot-1];
            if (shot<=monsters) break;
        }
        return --shot;
    }
};
