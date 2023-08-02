class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Permute(0,nums,ans);
        return ans;
    }
    private:
    void Permute(int index,vector<int> &nums,vector<vector<int>> & ans){
        if(index==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            Permute(index+1,nums,ans);
            swap(nums[index],nums[i]);
        }
    }
};