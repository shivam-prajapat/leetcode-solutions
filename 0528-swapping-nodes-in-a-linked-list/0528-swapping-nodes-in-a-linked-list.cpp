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
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* first = head;
        // step 1: reach the kth node from the start
        for(int i = 1; i < k; i++) {
            first = first->next;
        }

        // mark this node
        ListNode* frontNode = first;

        // step 2: find kth node from end
        ListNode* second = head;
        while(first->next != nullptr) {
            first = first->next;
            second = second->next;
        }

        // second is kth from end
        ListNode* endNode = second;

        // step 3: swap values
        int temp = frontNode->val;
        frontNode->val = endNode->val;
        endNode->val = temp;

        return head;
    }
};
