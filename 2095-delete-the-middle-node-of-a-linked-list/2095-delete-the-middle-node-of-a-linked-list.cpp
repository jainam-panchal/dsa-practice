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
    ListNode* deleteMiddle(ListNode* head) {
    
        if(head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        ListNode* prevSlow = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr) {
            if(fast->next == nullptr) {
                break;
            }
            prevSlow = slow;
            slow = slow->next;

            fast = fast->next->next;
        }

        prevSlow->next = slow->next;
        delete slow;

        return head;
        
    }
};