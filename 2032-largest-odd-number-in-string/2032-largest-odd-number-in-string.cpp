class Solution {
public:
    string largestOddNumber(string num) {
        string ans;
        if((num[num.size()-1]-'0')%2==1) return num;
        else{
            int index=-1;
            for(int i=num.size()-1;i>=0;i--){
                if(num[i]=='0') continue;
                else if((num[i]-'0')%2==1){
                    ans= num.substr(0,i+1);
                    //index=i;
                    break;
                }
            }
            
        }
        
        return ans;
    }
};