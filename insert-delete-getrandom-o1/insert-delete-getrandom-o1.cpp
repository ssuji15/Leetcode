class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> cache;
    RandomizedSet() {
        nums = {};
        cache = {};
    }
    
    bool insert(int val) {
        if(cache.find(val) == cache.end() || cache[val] == -1) {
            nums.push_back(val);
            cache[val] = nums.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(cache.find(val) == cache.end() || cache[val] == -1) {
            return false;
        }
        int valIdx = cache[val];
        int lastIdx = nums.size()-1;
        nums[valIdx] = nums[lastIdx];
        cache[nums[lastIdx]] = valIdx;
        cache[val] = -1;
        nums.pop_back();
        return true;
    }
    
    int getRandom() {
        int idx = rand()%nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */