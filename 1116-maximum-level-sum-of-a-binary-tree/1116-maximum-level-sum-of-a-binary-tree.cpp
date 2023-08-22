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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        priority_queue<pair<long long int,int>> pq;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int prev=INT_MAX;
        while(!q.empty()){
            int n=q.size();
            long long int sum=0;
            level++;
            while(n>0){
                TreeNode*temp= q.front();
                sum+=(temp->val);
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                n--;
            }
            if(prev==sum) continue;
            else{
                pq.push({sum,level});
                prev=sum;
            } 
            
        }
        return pq.top().second;
      
    }
};