class Solution {
public:
    vector<string> result;
    void solve(int idx, string s) {
        
        if(idx == s.length()) {
           result.push_back(s); 
           return; 
        }
        
        solve(idx+1, s);

        if(s[idx] >= 'a' && s[idx] <= 'z') {
            s[idx] = s[idx] - 'a' + 'A';
            solve(idx+1, s);
        } else if(s[idx] >= 'A' && s[idx] <= 'Z') {
            s[idx] = s[idx] - 'A' + 'a';
            solve(idx+1, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        solve(0, s);
        return result;
    }
};