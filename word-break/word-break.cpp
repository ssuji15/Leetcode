class Solution {
public:
    unordered_map<int,bool> dp;
    
    bool canBreak(int idx, string &s,unordered_map<string,bool> &words) {
        
        if(idx == s.length()) return true;
        
        if(dp.find(idx) != dp.end()) return dp[idx];

        string str = "";
        
        for(int i=idx;i<s.length();i++) {
            str += s[i];
            if(words.find(str) != words.end() && canBreak(i+1, s, words)) {
                return true;
            }
        }
        
        dp[idx] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        dp = {};
        unordered_map<string,bool> words;
        
        for(int i=0;i<wordDict.size();i++) {
            words[wordDict[i]] = true;
        }
        
        return canBreak(0,s,words);
    }
};