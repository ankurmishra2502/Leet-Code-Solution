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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root) return 0;
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long int sum=0;
            while(n>0){
                TreeNode*temp= q.front();
                sum+=(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                n--;
            }
            pq.push(sum);
            if(pq.size()>k) pq.pop();
        }
        if(pq.size()<k) return -1;
        else return pq.top();
    }
};