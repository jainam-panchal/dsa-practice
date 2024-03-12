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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        int presum = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        unordered_map<int, ListNode*> map;
        map[0] = dummy;
        
        
        while(head != nullptr) {
            presum += head->val;
            
            // delete
            if(map.find(presum) != map.end()) {
                ListNode* start = map[presum];
                ListNode* temp = start->next;
                int psum = presum;
                
                while(temp != head) {
                    psum += temp->val;
                    map.erase(psum);
                    
                    temp = temp->next;
                }
                
                start->next = head->next;
            }
            else {
                map[presum] = head;
            }
            
            head = head->next;
            
        }
        
        
        return dummy->next;        
    }
};