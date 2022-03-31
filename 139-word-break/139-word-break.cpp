class Solution {
public:
    bool canBreak(int idx, string &s, unordered_map<string,bool> &words, unordered_map<int,bool> &cache) {
        if(idx == s.length()) return true;
        if(cache.find(idx) != cache.end()) {
            return cache[idx];
        }
        string tmp = "";
        for(int i=idx;i<s.length();i++) {
            tmp += s[i];
            if(words.find(tmp) != words.end() && canBreak(i+1, s, words, cache)) {
                return true;
            }
        }
        cache[idx] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int,bool> cache;
        unordered_map<string,bool> words;
        for(int i=0;i<wordDict.size();i++) {
            words[wordDict[i]] = true;
        }
        return canBreak(0,s,words,cache);
    }
};