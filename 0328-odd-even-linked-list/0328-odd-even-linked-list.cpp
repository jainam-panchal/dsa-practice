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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == nullptr) return head;

        vector<int> arr;
        ListNode* odd = head;        
        
        while(odd != nullptr && odd->next != nullptr) {
            arr.push_back(odd->val);
            odd = odd->next->next;
        }
        if(odd != nullptr && odd->next == nullptr) {
            arr.push_back(odd->val);
        }
        
        ListNode* even = head->next;
        while(even != nullptr && even->next != nullptr) {
            arr.push_back(even->val);
            even = even->next->next;
        }
        if(even != nullptr && even->next == nullptr) {
            arr.push_back(even->val);
        }

        ListNode* temp = head;
        int i = 0;
        while(temp != nullptr) {
            temp->val = arr[i++];
            temp = temp->next;
        }
        
        return head;
    }
};