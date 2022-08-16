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
    Solution(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int pairSum(ListNode* head) {
        vector<int>nums;
        ListNode* temp=head;
        while(temp!=NULL){
            nums.push_back(temp->val);
            temp=temp->next;
        }
        int n=nums.size();
        int ans=INT_MIN;
        int a=0;
        int b=n-1;
        while(a<b){
            ans=max(ans,nums[a]+nums[b]);
            a++;
            b--;
        }
        return ans;
    }
};