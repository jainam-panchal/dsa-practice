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
        ListNode* first = head;
        for(int i=0 ; i<n-1 ; i++) {
            first = first->next;
        }
        
        ListNode* temp = first;
        ListNode* second = head;
        while(temp->next != nullptr) {
            second = second->next;
            temp = temp->next;
        }
        
        // cout << first->val << " " << second->val << endl;
        int backup = first->val;
        first->val = second->val;
        second->val = backup;
        
        return head;
        
    }
};