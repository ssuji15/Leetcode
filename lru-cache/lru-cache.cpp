class LRUCache {
public:
    int maxCapacity, curCapacity;
    list<pair<int,int>> LRU;
    unordered_map<int, std::list<pair<int,int>>::iterator> cache;

    LRUCache(int capacity) {
        this->maxCapacity = capacity;
        this->curCapacity = 0;
        LRU = {};
    }
    
    int get(int key) {

        if(cache.find(key) != cache.end()) {
            LRU.push_front({key,(*(cache[key])).second});
            LRU.erase(cache[key]);
            cache[key] = LRU.begin();
            return (*(cache[key])).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            LRU.erase(cache[key]);
            LRU.push_front({key,value});
            cache[key] = LRU.begin();
        }
        else {
            if(curCapacity == maxCapacity) {
                pair<int,int> last = LRU.back();
                cache.erase(last.first);
                LRU.pop_back();
                curCapacity--;
            }
            curCapacity++;
            LRU.push_front({key,value});
            cache[key] = LRU.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */