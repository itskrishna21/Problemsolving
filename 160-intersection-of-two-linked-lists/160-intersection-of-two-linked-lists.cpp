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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0;
        int n2=0;
        
        ListNode* temp=headA;
        ListNode* tempB = headB;
        
        while(temp!=NULL){
            n1++;
            temp=temp->next;
        }
        
        while(tempB!=NULL){
            n2++;
            tempB=tempB->next;
        }
        temp=headA;
        tempB=headB;
        if(n1>n2){
            // temp=headA;
            int diff = n1-n2;
            while(diff!=0){
                temp=temp->next;
                diff--;
            }
            
        }
        else{
            // tempB=headB;
            int diff = n2-n1;
            while(diff!=0){
                tempB=tempB->next;
                diff--;
            }
        }
        while(temp!=NULL && tempB!=NULL){
            if(temp==tempB){
                return tempB;
            }
            temp=temp->next;
            tempB=tempB->next;
        }
        return NULL;
    }
};