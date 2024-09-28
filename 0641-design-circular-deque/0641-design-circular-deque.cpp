class MyCircularDeque {
public:
    int front;
    int rear;
    int *array;
    int length;
    MyCircularDeque(int k) {
        array=new int[k+1];
        length=k+1;
        rear=0;
        front=0;
    }

    bool insertFront(int value) {
        if((front-1+length)%length==rear)
        {
            return false;
        }
        front=(front-1+length)%length;
        array[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if((rear+1)%length==front)
        {
            return false;
        }       
        array[rear]=value;
        rear=(rear+1)%length;
        return true;
    }
    
    bool deleteFront() {
        if(rear==front)
        {
            return false;
        }
        front=(front+1)%length;
        return true;
    }
    
    bool deleteLast() {
        if(rear==front)
        {
            return false;
        }
        rear=(rear-1+length)%length;
        return true;
    }
    
    int getFront() {
        if(rear==front)
        {
            return -1;
        }
        return array[front];        
    }
    
    int getRear() {
        if(rear==front)
        {
            return -1;
        }
        return array[(rear-1+length)%length];
    }
    
    bool isEmpty() {
        return rear==front;
    }
    
    bool isFull() {
        if((rear+1)%length==front)
        {
            return true;
        }
        return false;
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