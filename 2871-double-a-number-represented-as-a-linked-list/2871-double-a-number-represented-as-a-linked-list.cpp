class Solution {
public:
    int dfs(ListNode* node) {
        if (!node) return 0;

        int carry = dfs(node->next);
        int val = node->val * 2 + carry;

        node->val = val % 10;
        return val / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = dfs(head);
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};
