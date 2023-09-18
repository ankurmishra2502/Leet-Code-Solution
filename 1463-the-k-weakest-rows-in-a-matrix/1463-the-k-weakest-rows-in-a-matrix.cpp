class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
         vector<int> result;
 
 for(int i=0;i<mat.size();i++){
    int soldiers=check_safe(mat[i]);
    
    result.push_back(soldiers);
 }
 vector<int>index;
 index=result;
 
 vector<int>safe;

 sort(result.begin(),result.end());
 for(int i=0;i<k;i++){
    safe.push_back(result[i]);
 }
 vector<int> final_val=final(safe,index);
        return final_val;
    }
private:
 int check_safe(vector<int> check){
    int count=0;
    for(int i=0;i<check.size();i++){
        if(check[i]==1){
            count++;
        }
    }
    return count;
}
vector<int> final(vector<int> safe,vector<int> index){
    vector<int> final;
    for(int i=0;i<safe.size();i++){
       
        for(int j=0;j<index.size();j++){
            if(index[j]==safe[i]){
                final.push_back(j);
                index[j]=-1;
                break;
            }
        }
    }
    return final;
}
 
};