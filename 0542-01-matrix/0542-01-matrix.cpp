class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size(),cnt=0;
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!nums[i][j]) q.push({i,j});
            }
        }
        while(!q.empty()){
            int l=q.size();
            while(l--){
                pair<int,int> a=q.front();
                q.pop();
                int i= a.first,j=a.second;
                if(ans[i][j]!=-1) continue; 
                ans[i][j]=cnt;
                if(i>0 && nums[i-1][j] && ans[i-1][j]==-1) q.push({i-1,j});
                if(j>0 && nums[i][j-1] && ans[i][j-1]==-1) q.push({i,j-1});
                if(i<m-1 && nums[i+1][j] && ans[i+1][j]==-1) q.push({i+1,j});
                if(j<n-1 && nums[i][j+1] && ans[i][j+1]==-1) q.push({i,j+1});
            }   
            cnt++; 
        }
        return ans;
    }
};