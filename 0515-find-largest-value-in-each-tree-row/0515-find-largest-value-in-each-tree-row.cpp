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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n= q.size();
            vector<int> temp;
            while(n>0){
                TreeNode* val =q.front();
                temp.push_back(val->val);
                q.pop();
                if(val->left) q.push(val->left);
                if(val->right) q.push(val->right);
                n--;
            }
            int max_val = *max_element(temp.begin(),temp.end());
            ans.push_back(max_val);
        }
        return ans;
    }
};