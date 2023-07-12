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
    bool func(TreeNode *l, TreeNode *r){
        if(!l && !r) return true ;
        if(!l || !r) return false ;

        if(l->val != r->val) return false ;

        return func(l->left, r->right) && func(l->right, r->left) ;
    }

    bool isSymmetric(TreeNode* root) {
        return func(root->left, root->right) ;
    }
};