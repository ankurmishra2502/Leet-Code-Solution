class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& res) {
        vector<int> adjmatrix[n];
        for(auto x:edges){
            adjmatrix[x[0]].push_back(x[1]);
            adjmatrix[x[1]].push_back(x[0]);
        }
        map<int,int> vis;
        for(auto x:res){
            vis[x]=1;
        }
        if(vis[0]>0) return 0;
        vector<bool> visted(n,false);
        queue<int> q;
        q.push(0);
        visted[0]=true;
        int ans=1;
        while(!q.empty()){
            auto parent= q.front();
            q.pop();
            for(auto x:adjmatrix[parent]){
                if(!visted[x] && vis[x]==0){
                    visted[x]=true;
                    ans++;
                    q.push(x);
                }
            }
        }
        return ans;
    }
};