class MyCircularQueue {
public:
    vector<int> q;
    int n;
    int start,end,len;
    MyCircularQueue(int k) {
        q.resize(k);
        start=0;end=0;len=0;
        n=k;
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        if(isEmpty())
        {
            start=0,end=0,len=1;
            q[end]=value;
            return true;
        }
        end=(end+1)%n;
        q[end]=value;
        ++len;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        start=(start+1)%n;
        --len;
        return true;
    }
        
    int Front() {
        return (isEmpty()?-1:q[start]);
    }
    
    int Rear() {
        return (isEmpty()?-1:q[end]);
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==n;
    }
};