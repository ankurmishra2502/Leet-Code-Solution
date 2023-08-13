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
    ListNode* doubleIt(ListNode* head) {
        vector<int> temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        if(temp.size() == 0) return new ListNode(0);
        int carry=0;
        for(int i=temp.size()-1;i>=0;i--){
            int val= temp[i]*2;
            temp[i]= val%10+carry;
            carry= val/10;
        }
        if(carry!=0) temp.insert(temp.begin(),carry);
        //reverse(ans.begin(),ans.end());
        ListNode*head1= NULL;
        ListNode*tail=NULL;
        for(auto x:temp){
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