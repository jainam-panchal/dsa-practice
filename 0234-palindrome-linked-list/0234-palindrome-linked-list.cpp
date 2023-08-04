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
    bool isPalindrome(ListNode* head) {
       
        string linkedlist = "";
        
        // add elements to string
        while(head != nullptr) {
            linkedlist += (char)head->val;
            head = head->next;
        }
        
        // check palindrome
        int n = linkedlist.size();
        for(int i=0 ; i<n ; i++) {
            if(linkedlist[i] != linkedlist[n-i-1])
                return false;
        }
        
        // true case for palindrome
        return true;
        
    }
};