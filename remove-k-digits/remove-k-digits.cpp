class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.length();i++) {
            if(st.empty()) st.push(num[i]);
            else {
                while(!st.empty() && k > 0 && num[i] < st.top()) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
        }
        while(!st.empty() && k>0) {
            st.pop();
            k--;
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        while(res.length() > 0 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        if(res.length() == 0) res += '0';
        return res;
    }
};