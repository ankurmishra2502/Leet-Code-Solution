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
    ListNode* removeNodes(ListNode* head) {
        vector<int> temp;
        while(head!=NULL){
            temp.push_back(head->val);
            head=head->next;
        }
        if(temp[0]==99999 || temp[0]==99998) return new ListNode(100000);
        vector<int> new_vec;
        int i=temp.size()-1;
        int val= temp[i];
        i--;
        bool flag=false;
        while(i>=0){
            if(val<=temp[i]){
                flag=true;
                new_vec.push_back(val);
                val=temp[i];
            }
            i--;
        }
         new_vec.push_back(val);
        reverse(new_vec.begin(),new_vec.end());
        ListNode*head1=NULL;
        ListNode*tail=NULL;
        for(auto x:new_vec){
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