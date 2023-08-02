class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int n=h.size();
        int m=h[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dp[0][0]=0;
        int Row[4]={0,1,0,-1};
        int Col[4]={1,0,-1,0};
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row== n-1 && col==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int newRow= Row[i]+row;
                int newCol= Col[i]+col;

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m){
                    int effort= max(abs(h[row][col]-h[newRow][newCol]),diff);
                    if(effort< dp[newRow][newCol]){
                        dp[newRow][newCol]=effort;
                        pq.push({effort,{newRow,newCol}});
                    }
                }
            }
        }
        return 0;
    }
};