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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Approach 1 -> get count - n and remove the element
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL) {
            temp = temp->next;
            count++;
        }
        n = count - n;
        
        // edge case: remove the first node
        if(n == 0) {
            return head->next;
        }
        
        // remove the node
        temp = head;
        for(int i = 0; i < n-1; i++) {
            temp = temp->next;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};
