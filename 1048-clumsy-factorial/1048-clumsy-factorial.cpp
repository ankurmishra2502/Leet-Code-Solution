class Solution {
public:

    int clumsy(int n) {
        vector<int> vec;
        vec.push_back(n);
        int op = 1;
        for(int i=n-1; i>0; i--){
            int x = vec[vec.size()-1];
            if(op==1){
                vec.pop_back();
                vec.push_back(x*i);
                op=2;
                continue;
            }
            else if(op==2){
                vec.pop_back();
                vec.push_back(x/i);
                op=3;
                continue;

            }
            else if(op==3){
               vec.pop_back();
                vec.push_back(x+i);
                op=4;
                continue;
            }
            else if(op==4){
                vec.push_back(-1*i);
                op=1;
            }
        }

        int ans =0;
        int j=vec.size()-1;
        while(j>=0){
            ans += vec[j];
            j--;
        }
        return ans;
    }
};