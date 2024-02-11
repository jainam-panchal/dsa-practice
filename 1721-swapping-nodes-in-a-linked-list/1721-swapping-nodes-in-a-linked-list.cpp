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
    ListNode* swapNodes(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        if(count == 1) {
            return head;
        }
        
        ListNode* prev1 = head;
        for(int i=0 ; i<n-1 ; i++) {
            prev1 = prev1->next;
        }
        
        ListNode* prev2 = head;
        for(int i=0 ; i<count-n ; i++) {
            prev2 = prev2->next;
        }
        
        int bk = prev1->val ;
        prev1->val = prev2->val;
        prev2->val = bk;
        
        return head;
        
        
    }
};