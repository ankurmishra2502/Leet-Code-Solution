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
    int sumEvenGrandparent(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            TreeNode*temp= q.front();
            q.pop();
            if(temp->val %2==0){
                
                if(temp->left!=NULL){
                    if(temp->left->left!=NULL)
                    sum+=temp->left->left->val;
                    if(temp->left->right!=NULL)
                    sum+=temp->left->right->val;
                }
                if(temp->right!=NULL){
                    if(temp->right->right!= NULL)
                    sum+=temp->right->right->val;
                    if(temp->right->left!= NULL)
                    sum+=temp->right->left->val;
                }
                cout<<temp->val<<" "<<sum<<endl;
            }
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return sum;
    }
};