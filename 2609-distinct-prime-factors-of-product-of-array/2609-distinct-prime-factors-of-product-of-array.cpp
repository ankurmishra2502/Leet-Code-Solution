class Solution {
public:
    void solve(long long int n,vector<int>&factor){
      int x=2;
      while(n>1){
        if(n%x==0){
          factor.push_back(x);
          n/=x;
        }
        else x++;
      }
    }
    int distinctPrimeFactors(vector<int>& nums) {
     vector<int> factor;
     for(auto x:nums){
       solve(x,factor);
     }  
     set<int> s(factor.begin(),factor.end());
     return s.size(); 
    }
};