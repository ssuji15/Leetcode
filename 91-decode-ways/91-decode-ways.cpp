class Solution {
public:
    vector<int> cache;
    int numDecodings(int idx, string &s) {
        if(idx >= s.length()) return 1;
        if(cache[idx] != -1) return cache[idx];
        
        int ans = 0;
        int num1 = s[idx]-'0';

        if(num1 >= 1 && num1 <= 9) {
            ans = numDecodings(idx+1, s);
        }
        
        if(idx+1 < s.length()) {
            int num2 = (s[idx]-'0')*10 + s[idx+1]-'0';
            if(num2 >= 10 && num2 <= 26) {
                ans += numDecodings(idx+2, s);
            }
        }
        cache[idx] = ans;
        return ans;
    }
    int numDecodings(string s) {
        cache = vector<int>(s.length(), -1);
        return numDecodings(0,s);
    }
};