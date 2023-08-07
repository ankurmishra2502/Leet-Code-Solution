/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        while(head!=NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        stack<int> st;
        st.push(0);
        for(int i=ans.size()-1;i>=0;i--){
        int curr=ans[i];
        while((st.top()!=0)&&(st.top()<=curr)){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
        for(auto x:ans) cout<<x<<" ";
        return ans;
    }
};
