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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            n++;
        }
        
        int numNodes = n / k;
        int extras = n % k;
        
        vector<ListNode*> res;
        temp = head;
        
        while(temp) {
            res.push_back(temp);
            int currLen = 1;
            while(currLen < numNodes) {
                temp = temp->next;
                currLen++;
            }
            
            if(extras > 0 && n > k) {
                temp = temp->next;
                extras--;
            }
            
            ListNode* x = temp->next;
            temp->next = nullptr;
            temp = x;
        }
        
        while(n < k) {
            res.push_back(nullptr);
            n++;
        }
        
        return res;
    }
};