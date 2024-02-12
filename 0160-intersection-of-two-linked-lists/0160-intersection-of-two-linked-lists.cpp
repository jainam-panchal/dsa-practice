/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1 = 0;
        ListNode* temp = headA;
        while(temp != nullptr) {
            temp = temp->next;
            size1++;
        }
        
        int size2 = 0;
        temp = headB;
        while(temp != nullptr) {
            temp = temp->next;
            size2++;
        }
        
        int diff = abs(size1 - size2);
        if(size1 > size2) {
            temp = headA;
            for(int i=0 ; i<diff ; i++) {
                headA = headA->next;
            }
        }
        else {
            temp = headB;
            for(int i=0 ; i<diff ; i++) {
                headB = headB->next;
            }
        }
        
        while(headA != nullptr && headB != nullptr)  {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        
        return nullptr;
    }








};