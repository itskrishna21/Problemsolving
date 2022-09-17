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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int>arr;
        int size = 0;
        
        ListNode* temp = head;
        
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        
        temp = head;
        size=(size/k)*k;
        
        while(size--){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        temp = head;
        int en = k-1;
        
        while(en<arr.size()){
            int t = en;
            int c = k;
            while(c--){
                temp->val = arr[en];
                en--;
                temp=temp->next;
            }
            en = t+k;
            
        }
        
        return head;
    }
};