class Solution {
public:
    string decodeString(string s) {
        stack<string> st1;
        stack<int> st2;
        
        string curString = "", finalString = "";
        int curNum = 0;
        
        for(int i=0;i<s.length();i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                curNum = curNum * 10 + (s[i]-'0');
            }
            else if(s[i] == '[') {
                st2.push(curNum);
                st1.push(curString);
                curNum = 0;
                curString = "";
                
            }
            else if(s[i] == ']') {
                string temp = "";
                int repeat = st2.top();
                st2.pop();
                for(int i=0;i<repeat;i++) {
                    temp += curString;
                }
                curString = st1.top() + temp;
                st1.pop();
            }
            else {
                curString += s[i];
            }
        }
        return curString;
    }
};