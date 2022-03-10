class MyCircularQueue {
public:
    // vector of int for the actual queue
    // head and tail both set at -1 for when nothing is in the queue
    // cap is the cap of the queue
    vector<int> queue;
    int head = -1, tail = -1, cap;
    
    /** Initialize your data structure here. Set the cap of the queue to be k. */
    MyCircularQueue(int k) {
        queue = vector<int>(k);
        cap = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(head == -1)
        {
            queue[0] = value;
            tail = 1%cap;
            head = 0;
        }
        else if(head == tail)
        {
            return false;
        }
        else
        {
            queue[tail] = value;
            tail = (tail + 1)%cap;
        }
        
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(head == -1)
        {
            return false;
        }
        
        // since circular queues are FIFO, this is a pop_front function
        // by moving the head 1 forward and modulo for cap
        // head is now on the next element with the previous first being removed
        head = (head + 1)%cap;
        
        if(head == tail)
        {
            head = -1;
            tail = -1;
        }
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(head == -1)
        {
            return -1;
        }
        
        return queue[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(head == -1)
        {
            return -1;
        }
        else if(tail > 0)
        {
            return queue[tail - 1];
        }
        else
        {
            return queue.back();
        }
        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(head == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(head != -1 && head == tail)
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */