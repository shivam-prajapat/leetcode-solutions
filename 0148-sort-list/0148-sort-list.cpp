class Solution {
public:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Count length of list
        int length = 0;
        ListNode* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }

        ListNode dummy(0);
        dummy.next = head;

        // step = size of sublists to merge
        for (int step = 1; step < length; step *= 2) {
            ListNode* prev = &dummy;
            ListNode* curr = dummy.next;

            while (curr) {
                // First sublist
                ListNode* left = curr;

                // Get the right sublist head
                ListNode* right = nullptr;
                ListNode* tail = nullptr;

                int i = 1;
                while (i < step && curr->next) {
                    curr = curr->next;
                    i++;
                }

                // Now curr is at end of left sublist
                right = curr->next;
                curr->next = nullptr;  // break

                curr = right;
                i = 1;

                // Move curr to end of right sublist
                while (i < step && curr && curr->next) {
                    curr = curr->next;
                    i++;
                }

                // Save next part
                if (curr) {
                    tail = curr->next;
                    curr->next = nullptr;  // break
                }

                // Merge left and right
                ListNode* merged = merge(left, right);
                prev->next = merged;

                // Move prev to end of merged list
                while (prev->next) prev = prev->next;

                curr = tail;
            }
        }

        return dummy.next;
    }
};
