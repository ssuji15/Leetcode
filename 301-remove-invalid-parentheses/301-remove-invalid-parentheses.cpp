class Solution {
public:
    void addInResult(set<string> &result, string &temp) {
        if(result.size() == 0) {
            result.insert(temp);
        }
        else if(result.begin()->length() < temp.length()) {
            result = {temp};
        }
        else if(result.begin()->length() == temp.length()) {
            result.insert(temp);
        }
    }
    void findAll(int idx, string &s, int left, set<string> &result, string &temp) {
        if(idx == s.length()) {
            if(left == 0) {
                addInResult(result, temp);
            }
            return;
        }
        
        if(s[idx] == '(') {
            findAll(idx+1, s, left, result, temp);
            temp.push_back(s[idx]);
            findAll(idx+1, s, left+1, result, temp);
            temp.pop_back();
        }
        else if(s[idx] == ')') {
            if(left > 0) {
                temp.push_back(s[idx]);
                findAll(idx+1, s, left-1, result, temp);
                temp.pop_back();
            }
            findAll(idx+1, s, left, result, temp);
        }
        else {
            temp.push_back(s[idx]);
            findAll(idx+1, s, left, result, temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> result;
        string temp = "";
        findAll(0,s,0,result,temp);
        vector<string> res(result.begin(), result.end());
        return res;
    }
};