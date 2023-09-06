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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        vector<int> nunubhai;
        int sum=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==0){
                if(sum==0) continue;
                else nunubhai.push_back(sum);
                sum=0;
            }
            else{
                sum+=temp[i];
            }
        }
        if(sum>0) nunubhai.push_back(sum);
        ListNode*head1=NULL;
        ListNode*tail=NULL;
        for(auto x:nunubhai){
            ListNode*n= new ListNode(x);
            if(head1==NULL){
                head1=n;
                tail=n;
            }
            else{
                tail->next=n;
                tail=n;
            }
        }
    return head1;
    }
};