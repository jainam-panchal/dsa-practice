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
    ListNode* helper(ListNode* head, int &maxi) {
        if(head == nullptr) {
            return nullptr;
        }
        
        head->next = helper(head->next, maxi);
        
        if(head->val >= maxi) {
            maxi = head->val;
            return head;
        } 
        else if(head->val < maxi) {
            ListNode* temp = head->next;
            delete head;
            return temp;
        }
        
        return head;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        if(head->next == nullptr)
            return head;
        
        int maxi = -1;
        dummy->next = helper(head, maxi);
        
        return dummy->next;
    }
};