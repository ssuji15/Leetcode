class Solution {
public:
    vector<string> result;
    void generate(int open, int close, string &temp) {
        if(open == 0 && close == 0) {
            result.push_back(temp);
            return;
        }
        
        if(open > 0) {
            temp += '(';
            generate(open-1, close+1, temp);
            temp.pop_back();
        }
        
        if(close > 0) {
            temp += ')';
            generate(open, close-1, temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp = "";
        generate(n,0,temp);
        return result;
    }
};