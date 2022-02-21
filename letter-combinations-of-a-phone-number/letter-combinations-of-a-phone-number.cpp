class Solution {
public:
    vector<vector<char>> phone = {
        {},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
    };
    
    void combinations(int idx, string &digits, vector<string> &result,string temp) {
        if(idx == digits.length()) {
            result.push_back(temp);
            return;
        }
        
        int num = digits[idx]-'0';

        for(int i=0;i<phone[num].size();i++) {
            combinations(idx+1, digits, result, temp+phone[num][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        vector<string> result;
        combinations(0,digits,result,"");
        return result;
    }
};