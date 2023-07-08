class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
         vector<int> temp(words.size()+1,0);
    vector<int> ans;
    for(int i=0;i<words.size();i++){
        if((words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u') && ( words[i][words[i].size()-1]=='a' || words[i][words[i].size()-1]=='e' || words[i][words[i].size()-1]=='i' || words[i][words[i].size()-1]=='o' || words[i][words[i].size()-1]=='u' )){
            temp[i+1]=1;
        }
        temp[i+1]+=temp[i];

    } 
    for(auto &i: queries){
            ans.push_back(temp[i[1]+1]-temp[i[0]]);
        }
    return ans;
    }
};