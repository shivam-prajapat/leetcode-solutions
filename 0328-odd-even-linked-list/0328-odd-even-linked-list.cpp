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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;             // 1st node
        ListNode* even = head->next;      // 2nd node
        ListNode* evenHead = even;        // store even head

        while (even && even->next) {
            odd->next = even->next;       // link odd nodes
            odd = odd->next;

            even->next = odd->next;       // link even nodes
            even = even->next;
        }

        odd->next = evenHead;             // join even list at end
        return head;
    }
};
