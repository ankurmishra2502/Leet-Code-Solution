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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int ListLen = 0, eachLen = 0, remain = 0, size = 0, len = 0;
		ListNode *cur = NULL, *prev = NULL, *newHead = NULL;
		vector<ListNode*> ans = vector<ListNode*>(k, NULL);
		cur = head;
		while(cur != NULL) {
			ListLen++;
			cur = cur->next;
		}

		eachLen = ListLen / k;
		remain = (ListLen % k);

		cur = head;
		newHead = head;

		len = eachLen + (remain > 0 ? 1 : 0);
		remain--;

		while(cur != NULL) {
			if (--len == 0) {
				prev = cur;
				cur = cur->next;
				prev->next = NULL;
				ans[size++] = newHead;
				newHead = cur;

				len = eachLen + (remain > 0 ? 1 : 0);
				remain--;

			} else {
				cur = cur->next;
			}
		}

		return ans;
    }
};