//622. Design Circular Queue
class MyCircularQueue {
    int *que, front, back, size;
public:
    
    MyCircularQueue(int k) {
        que = new int[k];
        size=k;
        front=back=-1;
    }
    
    bool enQueue(int value) {
        if(front==back+1 || (front==0 && back==size-1))
            return false;
        
        if(front==-1){
            front=back=0;
        } else if(back==size-1){
            back=0;
        } else {
            back++;
        }
        
        que[back]=value;
        return true;
    
    }
    
    bool deQueue() {
        if(front==-1)
            return false;
        if(front==back) {
            front=back=-1;
        }else if(front==size-1)
            front=0;
        else
            front++;
        
        
        return true;
    }
    
    int Front() {
        return front==-1?front:que[front];
    }
    
    int Rear() {
        return back==-1?back:que[back];
    }
    
    bool isEmpty() {
        return front==-1?true:false;
    }
    
    bool isFull() {
        if(front==back+1 || (front==0 && back==size-1))
            return true;
        
        return false;
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