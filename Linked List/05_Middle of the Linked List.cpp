//////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
int getLenght(ListNode* head){
    int len=0;
    ListNode* temp=head;
    while(temp != NULL){
        temp=temp->next;
        len++;
    }
    return len;
}
    ListNode* middleNode(ListNode* head) {
        int len=getLenght(head);

        ListNode* temp=head;
        int cnt=0;
        while(cnt < len/2){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
