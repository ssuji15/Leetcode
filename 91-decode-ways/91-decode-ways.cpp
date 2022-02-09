class Solution {
public:
    unordered_map<int,int> cache;
    int decode(int idx, string &s) {
        if(idx >= s.length()) {
            return 1;
        }
        
        if(cache.find(idx) != cache.end()) {
            return cache[idx];
        }
        
        int num = s[idx] - '0', ans = 0;
        if(num >= 1  && num <= 9) {
            ans += decode(idx+1, s);
        }
        else {
            cache[idx] = 0;
            return 0;
        }
        
        if(idx + 1 < s.length()) {
            num = num * 10 + (s[idx+1] - '0');
            
            if(num >= 1 && num <= 26) {
                ans += decode(idx+2, s);
            }
        }
        
        cache[idx] = ans;
        return ans;
    }
    int numDecodings(string s) {
        cache = {};
        return decode(0,s);
    }
};