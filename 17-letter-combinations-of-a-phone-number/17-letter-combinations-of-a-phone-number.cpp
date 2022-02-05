class Solution {
public:
    vector<string> result;
    unordered_map<char, vector<char>> chars;
    
    void init() {
        chars['2'] = {'a', 'b', 'c'};
        chars['3'] = {'d', 'e', 'f'};
        chars['4'] = {'g', 'h', 'i'};
        chars['5'] = {'j', 'k', 'l'};
        chars['6'] = {'m', 'n', 'o'};
        chars['7'] = {'p', 'q', 'r', 's'};
        chars['8'] = {'t', 'u', 'v'};
        chars['9'] = {'w', 'x', 'y', 'z'};
    }
    
    void dfs(int idx, string &digits, string &temp) {
        
        if(idx == digits.length()) {
            if(temp != "")
                result.push_back(temp);
            return;
        }
        
        for(int j=0;j<chars[digits[idx]].size();j++) {
            temp += chars[digits[idx]][j];
            dfs(idx+1, digits, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        result = {};
        chars = {};
        init();
        string temp = "";
        dfs(0,digits,temp);
        return result;
    }
};