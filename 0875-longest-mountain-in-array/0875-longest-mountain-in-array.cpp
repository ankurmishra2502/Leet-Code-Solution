class Solution {
public:
    int longestMountain(vector<int>& arr) {
  if(arr.size()<3) return 0;
  vector<int> enm;
  for(int i=1;i<arr.size()-1;i++){
    if(arr[i]>arr[i-1] && arr[i]>arr[i+1] && (i+1 <= (arr.size()-1))){
      enm.push_back(i);
    }
  }
  if(enm.empty()) return 0;
  int cnt=0;
  for(auto x:enm){
    
    int ans = 1;
    int prev=arr[x];
    int prev2=arr[x];
    int temp=x-1;
    int temp2=x+1;
    while(temp>=0){
      if(prev>arr[temp]) {
        ans++;
        prev=arr[temp];
      }
      else break;
      temp--;
    }
    while(temp2<arr.size()){
      if(prev2>arr[temp2]){
        ans++;
        prev2=arr[temp2];
      } 
      else break;
      temp2++;
    }
    cnt=max(cnt,ans);
  }
  return cnt;
    }
};