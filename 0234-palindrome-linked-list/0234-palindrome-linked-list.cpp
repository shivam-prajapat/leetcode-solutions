class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1. Find middle (slow will point to mid)
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. Reverse second half starting from slow->next
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Now prev is the head of reversed second half
        ListNode* p1 = head;
        ListNode* p2 = prev;

        // 3. Compare both halves
        while (p2) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};
