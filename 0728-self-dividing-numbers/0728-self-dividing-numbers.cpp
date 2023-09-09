class Solution {
public:
    bool solve(int num){
        bool flag=true;
        int x= num;
        while(x>0){
            int rem= x%10;
            if(rem==0) flag=false;
                
            else if(num%rem!=0){
                 flag=false;
                 break;
            }
            x/=10;
        }
        return flag;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(solve(i)) ans.push_back(i);
        }
        return ans;
    }
};