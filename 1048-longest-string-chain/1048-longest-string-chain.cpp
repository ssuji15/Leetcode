class Solution {
public:
    struct MyCompare {
        public: 
        bool operator() (string a, string b) {
            return a.length() < b.length();
        }
    };
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), MyCompare());
        unordered_map<string,int> cache;
        int ans = 1;
        vector<int> dp(words.size(), 1);
        for(int i=0;i<words.size();i++) {
            cache[words[i]] = i;
        }
        
        for(int i=0;i<words.size();i++) {
            for(int j=0;j<words[i].length();j++) {
                string newWord = words[i].substr(0,j) + words[i].substr(j+1);
                if(cache.find(newWord) != cache.end()) {
                    dp[i] = max(dp[i], dp[cache[newWord]] + 1);
                    ans = max(ans, dp[i]);
                }
            }
        }
        return ans;
    }
};