class Solution {
public:
    string longestPalindrome(string s) {
        int length = 1, start = 0, end = 0;
        for(int i=0;i<s.length();i++) {
             int left = i, right = i;
            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            
            int curLength = right-left+1;
            if(curLength > length) {
                length = curLength;
                start = left+1;
                end = right-1;
            }
            
            left = i;
            right = i+1;

            while(left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            
            curLength = right-left+1;
            if(curLength > length) {
                length = curLength;
                start = left+1;
                end = right-1;
            }
        }
        
        string res = "";
        for(int i=start;i<=end;i++) {
            res += s[i];
        }
        return res;
    }
};