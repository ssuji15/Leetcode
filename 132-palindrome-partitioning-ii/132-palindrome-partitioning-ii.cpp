class Solution {
public:
    unordered_map<int,int> cache;
    int minCut(string &s, int idx, vector<vector<bool>> &isPalindrome) {
        if(idx == s.length()) return 0;
        if(cache.find(idx) != cache.end()) {
            return cache[idx];
        }
        int cutsRequired = INT_MAX;
        for(int i=idx;i<s.length();i++) {
            if(isPalindrome[idx][i]) {
                if(i+1 == s.length()) {
                    cutsRequired = 0;
                }
                else {
                    cutsRequired = min(cutsRequired,1 + minCut(s,i+1,isPalindrome));
                }
            }
        }
        cache[idx] = cutsRequired;
        return cutsRequired;
        
    }
    int minCut(string s) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        cache = {};
        for(int i=0;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                if(i==0) {
                    isPalindrome[j][j+i] = true;
                }
                else if(s[j] == s[j+i]) {
                    if(i == 1) {
                        isPalindrome[j][j+i] = true;
                    }
                    else {
                        isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1];
                    }
                }
            }
        }
        
        return minCut(s,0,isPalindrome);
    }
};