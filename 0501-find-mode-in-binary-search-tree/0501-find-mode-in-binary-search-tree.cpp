/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        int temp=0;
        vector<int> ans;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n>0){
                TreeNode*temp= q.front();
                mp[temp->val]++;
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                n--;
            } 
        }
        for(auto x:mp) if(x.second > temp) temp = x.second;
        for(auto x: mp) if(x.second == temp) ans.push_back(x.first);
        
        return ans;
    }
};