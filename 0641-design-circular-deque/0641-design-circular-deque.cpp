struct Node {
    int val;
    Node* next;
    Node* prev;
    
    Node(int val , Node* next = NULL , Node* prev = NULL) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyCircularDeque {
private:
    Node* head;
    Node* rear;
    int cap;
    int size;
    
public:
    MyCircularDeque(int k) {
        head = NULL; 
        rear = NULL;
        this->cap = k;
        this->size = 0;
    }
    
    bool insertFront(int val) {
        if(isFull()) return false;
        
        if(head == NULL) {  // deque is empty
            head = new Node(val);
            rear = head;
        } else {
            Node* newHead = new Node(val);
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        
        size++;
        return true;
    }
    
    bool insertLast(int val) {
        if(isFull()) return false;
        
        if(head == NULL) {  // deque is empty
            head = new Node(val);
            rear = head;
        } else {
            Node* newNode = new Node(val, NULL, rear);
            rear->next = newNode;
            rear = newNode;
        }
        
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        
        if(size == 1) {
            delete head;
            head = NULL; 
            rear = NULL;
        } else {
            Node* newHead = head->next;
            delete head;
            head = newHead;
            head->prev = NULL;
        }
        
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        if(size == 1) {
            delete head;
            head = NULL; 
            rear = NULL;
        } else {
            Node* newRear = rear->prev;
            delete rear;
            rear = newRear;
            rear->next = NULL;
        }
        
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return rear->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
