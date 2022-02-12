class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> cache;
        unordered_map<char,bool> mapped;
        for(int i=0;i<s.length();i++) {
            if(cache.find(s[i]) == cache.end()) {
                if(mapped.find(t[i]) != mapped.end()) return false;
                cache[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            else {
                if(cache[s[i]] != t[i]) return false;
            }
        }
        return true;
    }
};