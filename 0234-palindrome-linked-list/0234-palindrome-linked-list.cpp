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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;

        struct ListNode* slow=head,*fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

        }
        struct ListNode* prev=nullptr,*curr=slow,*next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        struct ListNode*p1=head,*p2=prev;
        while(p2){
            if(p1->val!=p2->val)return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;

    }
};