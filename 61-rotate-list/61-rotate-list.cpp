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
    ListNode* rotateRight(ListNode* head, int k) {
    
        int size = 0;
    
        ListNode* t = head;
        
        while(t!=NULL)
        {
            size++;
            t = t->next;
        }
        
        if(size==0) return head;
        k = k%size;
        
        if(k==0) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(k--)fast = fast->next;
        
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast =fast->next;
        }
        
        ListNode* store = slow->next;
        slow->next = NULL;
        ListNode* temp = store;
        
        while(temp!=NULL && temp->next!=NULL) temp = temp->next;

        if(temp!=NULL) temp->next = head;
        
        return store;
    }
};