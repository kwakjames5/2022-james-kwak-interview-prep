class MyCircularDeque {
public:
    vector<int> queue;
    int head = -1, tail = -1, size = 0, cap;
    
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        queue = vector<int>(k);
        head = 0;
        tail = cap - 1;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size == cap)
        {
            return false;
        }
        else
        {
            head = (head - 1 + cap)%cap;
            queue[head] = value;
            size++;
        }
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size == cap)
        {
            return false;
        }
        
        tail = (tail + 1)%cap;
        queue[tail] = value;
        size++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0)
        {
            return false;
        }
        
        head = (head + 1) % cap;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0)
        {
            return false;
        }
        
        tail = (tail - 1 + cap) % cap;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size == 0)
        {
            return -1;
        }
        
        return queue[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size == 0)
        {
            return -1;
        }
        
        return queue[tail];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(size == 0)
        {
            return true;
        }
        else
        {
            return false;   
        }
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(size == cap)
        {
            return true;
        }
        else
        {
            return false;
        }
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