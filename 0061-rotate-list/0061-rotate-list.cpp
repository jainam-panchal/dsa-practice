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
    ListNode* rotateRight(ListNode* head, int k) {
        // if it has only one or zero node just return the node
         // or if k == 0 so no change just return the head
         if(head == nullptr || head->next == nullptr || k == 0) {
              return head;
         }

         // start count with 1 because we're at the first
         int count = 1;
         ListNode* temp = head;

         // count total nodes
         while(temp->next != nullptr) {
              count++;
              temp = temp->next;
         }

         // make it circluar
         temp->next = head;

         // to make the k recursive
         k = k % count;

         // just go to the newHead
         count = count - k;;
         while(count != 0) {
              temp = temp->next;     
              count--;
         }
         // assign new head
         head = temp->next;

         // remove the circluar part and define end of ll
         temp->next = nullptr;

         return head;
    }
};