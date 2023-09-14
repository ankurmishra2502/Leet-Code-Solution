class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> st;
        for(auto z:circles){
            int x= z[0];
            int y= z[1];
            int r= z[2];
            for(int i=x-r;i<=r+x;i++){
                for(int j=y-r;j<=r+y;j++){
                    if(pow((i-x),2)+pow((j-y),2)<=pow(r,2)){
                        st.insert({i,j});
                    }
                }
            }
        }
        return st.size();
    }
};