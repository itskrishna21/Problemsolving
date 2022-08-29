/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
       bool flag=true;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                flag=false;
                break;
            }
            

        }
        slow=head;
        while(!flag){
            if(slow==fast){
                
                return slow;
            }
            slow=slow->next;
            fast=fast->next;
            
        }
        return NULL;
    }
};