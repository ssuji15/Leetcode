class LRUCache {
public:
    int maxSize = 0;
    int curSize;
    unordered_map<int, list<vector<int>>::iterator> cache;
    list<vector<int>> myList;
    LRUCache(int capacity) {
        this->maxSize = capacity;
        this->curSize = 0;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            vector<int> temp = *(cache[key]);
            myList.erase(cache[key]);
            myList.push_front(temp);
            cache[key] = myList.begin();
            return (*cache[key])[1];
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        if(cache.find(key) != cache.end() && cache[key] != myList.end()) {
            auto itr = cache[key];
            myList.erase(itr);
            myList.push_front({key,value});
            cache[key] = myList.begin();
        }
        else if(this->curSize < this->maxSize) {
            myList.push_front({key,value});
            cache[key] = myList.begin();
            this->curSize++;
        }
        else {
            vector<int> temp = myList.back();
            cache.erase(temp[0]);
            myList.pop_back();
            myList.push_front({key,value});
            cache[key] = myList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */