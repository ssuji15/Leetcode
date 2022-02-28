class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> cache;
    bool isMatch(int i, string &s, int j, string &p) {
        if(i==s.length() && j == p.length()) return true;
        if(i==s.length() && p[j] == '*') return isMatch(i,s,j+1,p);
        if(i==s.length() && j+1 < p.length() && p[j+1] == '*') return isMatch(i,s,j+1,p);
        if(i==s.length() || j==p.length()) return false;
        
        if(cache.find(i) != cache.end() && cache[i].find(j) != cache[i].end()) {
            return false;
        }
        
        if(p[j] == '*') {
            int k;
            for(k=i;k<=s.length();k++) {
                if(k==s.length() || s[k] == p[j-1] || p[j-1] == '.') {
                    if(isMatch(k,s,j+1,p)) return true;
                }
                else break;
            }
            if(k<=s.length()) {
                cache[i][j] = isMatch(k,s,j+1,p);
                return cache[i][j];
            }
            cache[i][j] = false;
            return false;
        }
        else if(j+1 < p.length() && p[j+1] == '*') {
            cache[i][j] = isMatch(i,s,j+1,p);
            return cache[i][j];
        }
        else if(p[j] == '.' || s[i] == p[j]) {
            cache[i][j] = isMatch(i+1, s, j+1, p);
            return cache[i][j];
        }
        else {
            cache[i][j] = false;
            return false;
        }
    }
    bool isMatch(string s, string p) {
        cache = {};
        return isMatch(0,s,0,p);
    }
};