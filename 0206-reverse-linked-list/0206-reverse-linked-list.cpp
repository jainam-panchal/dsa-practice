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
private:
    ListNode* tempHead;
    ListNode* revUtil(ListNode* head) {
        
        // base condition
        if(head == nullptr) {
            return head;
        }
        
        // setting new head
        if(head->next == nullptr) {
            tempHead = head;
            return head;
        }
        
        // flip directions
        ListNode* node1 = revUtil(head->next);
        head->next = nullptr;
        node1->next = head;
        
        return head;
    }
    
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = revUtil(head);
        return tempHead;
    }
};