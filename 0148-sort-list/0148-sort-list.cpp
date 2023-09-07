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
    ListNode* merger(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1 != NULL) {
            temp->next = l1;
        }
        if(l2 != NULL) {
            temp->next = l2;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* temp = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp -> next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merger(l1,l2);
    }
};