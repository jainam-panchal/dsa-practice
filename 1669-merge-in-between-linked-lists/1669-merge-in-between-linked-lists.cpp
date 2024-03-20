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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head = list1;
        
        // go to a-1
        for(int i=0 ; i<a-1 ; i++) {
            list1 = list1->next;
        }
        ListNode* temp = list1->next;
        
        // go to the last node
        list1->next = list2;
        while(list1->next) {
            list1 = list1->next;
        }
        
        // go to b+1
        for(int i=0 ; i<b-a+1 ; i++) {
            ListNode* nextPtr = temp->next;
            delete(temp);
            temp = nextPtr;
        }
        
        list1->next = temp;
        
        return head;
    }
};