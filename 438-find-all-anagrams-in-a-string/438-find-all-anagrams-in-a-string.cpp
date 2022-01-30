class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> chars(26,0);
        vector<int> curChars(26,0);
        vector<int> result;
        
        for(int i=0;i<p.length();i++) {
            chars[p[i]-'a']++;
        }
        
        for(int i=0;i<s.length();i++) {
            curChars[s[i]-'a']++;
            
            if(i >= p.length()) {
                curChars[s[i-p.length()] -'a']--;
            }
            
            bool equal = true;
            for(int j=0;j<26;j++) {
                if(chars[j] != curChars[j]) equal = false;
            }
            
            if(equal) {
                result.push_back(i-p.length()+1);
            }
        }

        return result;
    }
};