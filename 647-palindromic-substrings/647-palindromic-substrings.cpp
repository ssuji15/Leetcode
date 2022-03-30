class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        int count = 0;
        for(int i=0;i<s.length();i++) {
            isPalindrome[i][i] = true;
            count++;
        }
        
        for(int i=1;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                if(i==1) {
                    isPalindrome[j][j+i] = s[j] == s[j+i];
                }
                else {
                    isPalindrome[j][j+i] = s[j] == s[j+i] && isPalindrome[j+1][j+i-1];
                }
                if(isPalindrome[j][j+i]) count++;
            }
        }
        return count;
    }
};