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
    ListNode* middleNode(ListNode* head) {
        
        if(head->next == nullptr) {
            return head;    
        }
        
        ListNode* slow = head;
        ListNode* high = head;
        
        while(slow != nullptr && high != nullptr && high->next != nullptr) {
            slow = slow->next;
            high = high->next->next;
        }
        
        if(head->next == nullptr) {
            return slow->next;
        }
        else {
            return slow;
        }
    }
};