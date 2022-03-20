class Solution {
public:
    int calculate(string s) {
        char op = '+';
        stack<int> st1;
        stack<char> st2;
        int ans = 0, cur = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == ' ') continue;
            else if(s[i] == '+' || s[i] == '-') {
                if(op == '+') {
                    ans += cur;
                }
                else {
                    ans -= cur;
                }
                cur = 0;
                op = s[i];
            }
            else if(s[i] == '(') {
                st1.push(ans);
                st2.push(op);
                ans = 0;
                op = '+';
            }
            else if(s[i] == ')') {

                if(op == '+') {
                    ans += cur;
                }
                else {
                    ans -= cur;
                }
                
                int temp1 = st1.top();
                st1.pop();
                char temp2 = st2.top();
                st2.pop();
                cout<<temp1<<" "<<ans<<" "<<op<<endl;
                if(temp2 == '-') {
                    ans = temp1 - ans;
                }
                else {
                    ans = temp1 + ans;
                }
                op = '+';
                cur = 0;
            }
            else {
                cur = cur * 10 + (s[i]-'0');
            }
        }
        if(op == '+') {
            ans += cur;
        }
        else {
            ans -= cur;
        }
        return ans;
    }
};