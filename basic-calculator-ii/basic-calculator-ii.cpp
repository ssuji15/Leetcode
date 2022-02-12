class Solution {
public:
    int calculate(string s) {
        int ans = 0,prevNum = 0, curNum = 0;
        char prevOp='+',curOp=0;
        
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') continue;
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                if(prevOp == '+' || prevOp == '-') {
                    ans += prevNum;
                    prevNum = prevOp == '+' ? curNum : -curNum;
                }
                else if(prevOp == '*') {
                    prevNum *= curNum;
                }
                else if(prevOp == '/') {
                    prevNum /= curNum;
                }
                prevOp = s[i];
                curNum = 0;
            }
            else {
                curNum = curNum * 10 + (s[i]-'0');
            }
        }
        if(prevOp == '+' || prevOp == '-') {
            ans += prevNum;
            ans += prevOp == '+' ? curNum : -curNum;
        }
        else if(prevOp == '*') {
            ans += prevNum * curNum;
        }
        else if(prevOp == '/') {
            ans += prevNum / curNum;
        }
        return ans;
    }
};