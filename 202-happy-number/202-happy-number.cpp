class Solution {
public:
    int getNext(int n) {
        int temp = 0;
        while(n != 0) {
            int d = n%10;
            n = n/10;
            temp += d * d;
        }
        return temp;
    }
    bool isHappy(int n) {
        unordered_map<int,bool> cache;
        cache[n] = true;
        while(n != 1) {
            n = getNext(n);
            if(cache.find(n) != cache.end()) {
                break;
            }
            cache[n] = true;
        }
        return n==1;
    }
};

