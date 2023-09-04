/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        // 1st step : insert new nodes parallel
        Node* iterator = head;
        Node* front = head;
        
        while(iterator != NULL) {
            Node* copy = new Node(iterator->val);
            front = iterator->next;
            copy->next = iterator->next;
            iterator->next = copy;
            
            iterator = front;
        }
        
        
        // 2nd Step : Put those random pointers
        iterator = head;
        while(iterator != NULL) {
            if(iterator->next != NULL) {
                if(iterator->random != NULL) {
                    iterator->next->random = iterator->random->next;
                }
            }
            iterator = iterator->next->next;
        }
        
        // 3rd Step : Make those two linkedlist independent
        Node* newHead = new Node(-1);
        Node* dummy = newHead;
        
        iterator = head;
        while(iterator != NULL) {
            Node* front = iterator->next->next;
            
            dummy->next = iterator->next;
            iterator->next = front;
            
            iterator = front;
            dummy = dummy->next;
        }
        
        return newHead->next;
        
    }
};