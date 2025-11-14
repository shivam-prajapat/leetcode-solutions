class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // 1. Find length and get tail
        ListNode* tail = head;
        int len = 1;

        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // 2. Reduce extra rotations
        k = k % len;
        if (k == 0) return head;

        // 3. Make the list circular
        tail->next = head;

        // 4. Find new tail: position = len - k
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // 5. New head is next of newTail
        ListNode* newHead = newTail->next;

        // 6. Break the circle
        newTail->next = nullptr;

        return newHead;
    }
};
