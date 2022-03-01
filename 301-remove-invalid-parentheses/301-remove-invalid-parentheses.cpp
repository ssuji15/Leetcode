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
            
        }
    }
    void findAll(int idx, string &s, int left, int leftRem, int rightRem,
                 set<string> &result, string &temp) {
        if(idx == s.length()) {
            if(left == 0 && leftRem == 0 && rightRem == 0) {
                result.insert(temp);
            }
            return;
        }
        
        if(s[idx] == '(') {
            if(leftRem > 0) {
                findAll(idx+1, s, left, leftRem-1, rightRem, result, temp);
            }

            temp.push_back(s[idx]);
            findAll(idx+1, s, left+1, leftRem, rightRem, result, temp);
            temp.pop_back();
        }
        else if(s[idx] == ')') {
            if(left > 0) {
                temp.push_back(s[idx]);
                findAll(idx+1, s, left-1, leftRem, rightRem, result, temp);
                temp.pop_back();
            }
            
            if(rightRem > 0) {
                findAll(idx+1, s, left, leftRem, rightRem-1, result, temp);
            }
        }
        else {
            temp.push_back(s[idx]);
            findAll(idx+1, s, left, leftRem, rightRem, result, temp);
            temp.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string> result;
        string temp = "";
        int left = 0, right = 0;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '(') left++;
            else if(s[i] == ')') {
                if(left > 0) left--;
                else right++;
            }
        }
        findAll(0,s,0,left,right,result,temp);
        vector<string> res(result.begin(), result.end());
        return res;
    }
};