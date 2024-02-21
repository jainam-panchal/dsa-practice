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
    ListNode* solve(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* curr = head;
        ListNode* nextCurr = curr->next;
        curr->next = nextCurr->next;
        nextCurr->next = curr;
        
        curr->next = solve(curr->next);
        
        return nextCurr;
    }
    
public:
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* newHead = new ListNode(1);
        newHead->next = head;
        
        // If no node or only one node
        if(newHead->next == nullptr || newHead->next->next == nullptr)
            return head;
        
        newHead->next = solve(head);
        
        return newHead->next;
        
    }
};