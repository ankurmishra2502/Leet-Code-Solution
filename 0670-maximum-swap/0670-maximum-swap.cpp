class Solution {

public:
    int element(vector<int>d,int ind,int target ){
  int index= -1;
  int value=INT16_MIN;
  for(int i=ind+1;i<d.size();i++){
    if(value<=d[i]){
      index=i;
      value=d[i];
    }
  }
  return index;
}
int maximumSwap(int num) {
    vector<int> digit;
    while(num>0){
    digit.push_back(num%10);
    num/=10;
    }
    int cnt=1;
    reverse(digit.begin(),digit.end());
    int j=0;
  
    for(int i=0;i<digit.size();i++){
        int val=element(digit,i,digit[j]);
        if(cnt==0) break;
        if(val== -1) j++;
        else if(val!= -1 && digit[i]<digit[val]) {
        int temp=digit[val];
        digit[val]=digit[i];
        digit[i]=temp;
        cnt--;
    } 
    
  }
  int val=0;
  for(auto x:digit){
      val=val*10 +x;
  }
  return val;

    }
};