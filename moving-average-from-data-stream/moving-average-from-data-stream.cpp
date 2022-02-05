class MovingAverage {
public:
    int maxSize;
    double total;
    deque<int> q;
    MovingAverage(int size) {
        this->maxSize = size;
        this->total = 0;
    }
    
    double next(int val) {
        if(q.size() == maxSize) {
            total -= q.front();
            q.pop_front();
        }
        total += val;
        q.push_back(val);
        return this->total / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */