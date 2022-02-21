class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> tCharCount;
        unordered_map<char,int> sCharCount;
        int tUniqueChars = 0, sNoOfChars = 0, ans = INT_MAX, startIdx = -1, endIdx = -1;
        string res="";

        for(int i=0;i<t.length();i++) {
            if(tCharCount[t[i]] == 0) {
                tUniqueChars++;
            }
            tCharCount[t[i]]++;
        }
                       
        for(int i=0,j=0;i<s.length();i++) {
            sCharCount[s[i]]++;
            if(sCharCount[s[i]] == tCharCount[s[i]]) {
                sNoOfChars++;
            }
            
            while(sNoOfChars == tUniqueChars) {
                int curLength = i-j+1;
                if(curLength < ans) {
                    ans = curLength;
                    startIdx = j;
                    endIdx = i;
                }
                
                sCharCount[s[j]]--;
                if(sCharCount[s[j]] < tCharCount[s[j]]) {
                    sNoOfChars--;
                }
                j++;
            }
        }
        
        if(ans == INT_MAX) {
            return "";
        }
        
        for(int i=startIdx;i<=endIdx;i++) {
            res += s[i];
        }
        
        return res;
    }
};