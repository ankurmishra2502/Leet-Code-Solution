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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        vector<int> nums;
        while(l1!=NULL && l2!=NULL){
            int sum= l1->val + l2->val;
            int max_val=sum + carry;
            nums.push_back(max_val%10);
            if(max_val>9) {
                carry=1;
            }
            else carry=0;

            
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=NULL){
            while(l1!=NULL){
                int sum=(l1->val)+ carry;
                nums.push_back(sum%10);
                if(sum>9) carry=1;
                else carry=0;
                l1=l1->next;
            }
        }
        else{
            while(l2!=NULL){
                int sum=(l2->val) + carry;
                nums.push_back(sum%10);
                if(sum>9) carry=1;
                else carry=0;
                l2=l2->next;
            }
        }

        if(carry==1) nums.push_back(1);
        ListNode*head1=NULL;
        ListNode*tail=NULL;
        for(auto x: nums){
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