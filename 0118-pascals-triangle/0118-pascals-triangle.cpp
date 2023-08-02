class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        if(n==2) return {{1},{1,1}};
        vector<int> nums={1,1};
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1,1});
        for(int i=2;i<n;i++){
            vector<int> temp;
            temp.push_back(1);
            int start=0;
            int j=start+1;
            while(j<nums.size()){
                temp.push_back(nums[start]+nums[j]);
                start++;
                j++;
            }
            temp.push_back(1);
            nums=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};