class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        int n1=0,n2=0;
        while(temp){
            n1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            n2++;
            temp=temp->next;
        }
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        if(n1>n2){
            int d=n1-n2;
            for(int i=0;i<d;i++){
                temp1=temp1->next;
            }
        }else if(n1<n2){
            int d=n2-n1;
            for(int i=0;i<d;i++){
                temp2=temp2->next;
            }
        }
        while(temp1){
            if(temp1==temp2)return temp1;
            temp1=temp1->next;
            temp2=temp2->next;

        }
        return NULL;
    }
};