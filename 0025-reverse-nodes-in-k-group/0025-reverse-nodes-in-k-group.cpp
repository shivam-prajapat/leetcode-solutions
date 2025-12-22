class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        int cnt=0;

        //check if k nodes exits

        while(cnt<k){
            if(temp==NULL){
                return head;
            }
            temp=temp->next;
            cnt++;
        }
        // recursively call for rest of the ll
        ListNode* prevNode=reverseKGroup(temp,k);
        //reverse current group 

        temp=head;cnt=0;
        while(cnt<k){
            ListNode* Next=temp->next;
            temp->next=prevNode;
            prevNode=temp;
            temp=Next;
            cnt++;

        }
        return prevNode;
            }
};