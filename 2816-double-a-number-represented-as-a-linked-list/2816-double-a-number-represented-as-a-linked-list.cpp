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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next;
        
        while(curr != nullptr) {
            next = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;

    }

public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* revList = reverse(head);
        
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        
        
        while(revList != nullptr) {
            int digit = revList->val;
            digit *= 2;
            digit = digit + carry;
            
            ListNode *newNode = new ListNode(digit % 10);
            carry = digit / 10;
            
            dummy->next= newNode;
            dummy = dummy->next;
            
            revList = revList->next;
        }
        
        if(carry != 0) {
            dummy->next = new ListNode(carry);
        }
        
        temp->next = reverse(temp->next);
        
        return temp->next;
    }
};