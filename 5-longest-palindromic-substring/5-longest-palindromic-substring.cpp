class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for(int i=0;i<s.length();i++) {
            dp[i][i] = true;
        }
        int startIdx = 0, endIdx = 0, length = 1;
        for(int i=1;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                int x = j, y = j+i;
                if(s[x] == s[y]) {
                    if(y == x+1) {
                        dp[x][y] = true;
                    }
                    else {
                        dp[x][y] = dp[x+1][y-1];
                    }
                }
                else {
                    dp[x][y] = false;
                }
                
                if(dp[x][y]) {
                    int curLength = y-x+1;
                    if(curLength > length) {
                        length = curLength;
                        startIdx = x;
                        endIdx = y;
                    }
                }
            }
        }
        string result = "";
        while(startIdx <= endIdx) {
            result += s[startIdx];
            startIdx++;
        }
        return result;
    }
};