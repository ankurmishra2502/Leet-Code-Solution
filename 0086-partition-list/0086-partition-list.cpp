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
    ListNode* partition(ListNode* head, int x) {
     vector<int> clmc;
     vector<int> tt;
     while(head!=NULL){
         if(head->val<x) clmc.push_back(head->val);
         else tt.push_back(head->val);
         head=head->next;
     }
     for(auto x:tt) clmc.push_back(x);
     ListNode*head1= NULL;
     ListNode*tail=NULL;
     for(int i=0;i<clmc.size();i++){
            ListNode*n=new ListNode(clmc[i]);
            if(head1==NULL){
                head1=n;
                tail=n;
            }else{
                tail->next=n;
                tail=n;
            }
        }
    return head1;
    }
};