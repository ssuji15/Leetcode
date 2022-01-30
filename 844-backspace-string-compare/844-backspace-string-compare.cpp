class Solution {
public:
    string transform(string &s) {
        deque<char> ch;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '#') {
                if(!ch.empty()) {
                    ch.pop_back();
                }
            }
            else {
                ch.push_back(s[i]);
            }
        }
        string res(ch.begin(), ch.end());
        return res;
    }
    
    bool backspaceCompare(string s, string t) {
        
        s = transform(s);
        t = transform(t);
        return s.compare(t) == 0;
    }
};