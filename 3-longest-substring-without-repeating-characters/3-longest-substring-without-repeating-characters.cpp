class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> cache;
        int i=0,j=0,ans=0;
        for(;i<s.length();i++) {
            if(cache.find(s[i]) != cache.end() && cache[s[i]] >= j) {
                j = cache[s[i]]+1;
            }
            cache[s[i]] = i;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};