class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        if (!head) return head;        

        head = reverseLL(head);
        ListNode* ptr = head;
        ListNode* prev = nullptr;

        int carry = 0;
        while (ptr != nullptr) {
            int val = ptr->val * 2 + carry;  
            ptr->val = val % 10;            
            carry = val / 10;             

            prev = ptr;
            ptr = ptr->next;
        }

        if (carry > 0) {
            ListNode* newnode = new ListNode(carry);
            prev->next = newnode;
        }

        return reverseLL(head);
    }
};