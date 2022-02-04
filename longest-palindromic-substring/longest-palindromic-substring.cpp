class Solution {
public:
    string longestPalindrome(string s) {
        
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        int length = 1, startIdx = 0, endIdx = 0;
        for(int i=0;i<s.length();i++) {
            isPalindrome[i][i] = true;
        }
        
        for(int i=1;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                int newI = j;
                int newJ = j+i;
                
                if(s[newI] == s[newJ]) {
                    if(newI + 1 == newJ) {
                        isPalindrome[newI][newJ] = true;
                    }
                    else {
                        isPalindrome[newI][newJ] = isPalindrome[newI+1][newJ-1];
                    }
                }
                
                if(isPalindrome[newI][newJ]) {
                    if(newJ - newI + 1 > length) {
                        length = newJ-newI+1;
                        startIdx = newI;
                        endIdx = newJ;
                    }
                }
            }
        }
        
        string res = "";
        
        for(int i = startIdx;i<=endIdx;i++) {
            res += s[i];
        }
        
        return res;
    }
};