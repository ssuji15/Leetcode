class Solution {
public:
    unordered_map<int,unordered_map<int,bool>> cache;
    bool isMatch(int i, int j, string &s, string &p) {
        if(i==s.length() && j==p.length()) return true;
        if(i==s.length() && p[j] == '*') return isMatch(i,j+1,s,p);
        if(i==s.length() || j == p.length()) return false;

        if(cache.find(i) != cache.end() && cache[i].find(j) != cache[i].end()) return cache[i][j];
        cache[i][j] = false;
        if(s[i] == p[j] || p[j] == '?') {
            cache[i][j] = isMatch(i+1,j+1,s,p);
        }
        else if(p[j] == '*') {
            cache[i][j] = isMatch(i,j+1,s,p) || isMatch(i+1,j,s,p);
        }
        return cache[i][j];
    }
    bool isMatch(string s, string p) {
        return isMatch(0,0,s,p);
    }
};