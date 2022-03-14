class LFUCache {
public:
    map<int, list<int>> frequencyList;
    unordered_map<int,int> cache;
    unordered_map<int,int> keyFrequencies;
    unordered_map<int,list<int>::iterator> keyIterators;
    int maxCapacity = 0, curCapacity = 0, minFrequency = 1;
    LFUCache(int capacity) {
        frequencyList = {};
        cache = {};
        keyFrequencies = {};
        this->maxCapacity = capacity;
        this->curCapacity = 0;
        this->minFrequency = 1;
    }
    
    void addNewKeyInFrequency(int key, int value, int frequency) {
        frequencyList[frequency].push_front(key);
        cache[key] = value;
        keyFrequencies[key] = frequency;
        keyIterators[key] = frequencyList[frequency].begin();
        
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            put(key,cache[key]);
            return cache[key];
        }
        return -1;
    }
    
    void removeLeastFrequentlyUsed() {
            int frequency = this->minFrequency;
            int key = (frequencyList[frequency].back());
            cache.erase(key);
            keyFrequencies.erase(key);
            keyIterators.erase(key);
            frequencyList[frequency].pop_back();
            if(frequencyList[frequency].size() == 0) {
                frequencyList.erase(frequency);
                this->minFrequency++;
            }
    }
    
    void put(int key, int value) {
        if(this->maxCapacity == 0) return;
        if(cache.find(key) == cache.end()) {
            if(this->curCapacity < this->maxCapacity) {
                addNewKeyInFrequency(key,value,1);
                this->curCapacity++;
            }
            else {
                removeLeastFrequentlyUsed();
                addNewKeyInFrequency(key,value,1);
            }
            this->minFrequency = 1;
        }
        else {
            int frequency = keyFrequencies[key];
            frequencyList[frequency].erase(keyIterators[key]);
            if(frequencyList[frequency].size() == 0) {
                frequencyList.erase(frequency);
            }
            if(frequencyList[this->minFrequency].size() == 0) {
                this->minFrequency++;
            }
            addNewKeyInFrequency(key, value, frequency+1);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */