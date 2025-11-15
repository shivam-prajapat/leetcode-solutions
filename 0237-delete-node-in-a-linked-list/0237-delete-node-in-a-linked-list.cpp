class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;   // Copy next node value
        ListNode* temp = node->next;   // Store next node
        node->next = node->next->next; // Bypass next node
        delete temp;                   // Free memory
    }
};
