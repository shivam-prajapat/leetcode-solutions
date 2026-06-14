class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while (curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        
        int max_sum = 0;
        ListNode* head1 = head;
        ListNode* head2 = prev;
        
        while (head2 != nullptr) {
            max_sum = max(max_sum, head1->val + head2->val);
            head1 = head1->next;
            head2 = head2->next;
        }
        
        return max_sum;
    }
};