class Solution {
public:
    vector<vector<string>> result;
    void partition(string &s, int idx, vector<string> &curPartition,
                   vector<vector<bool>> &isPalindrome) {
        if(idx == s.length()) {
            result.push_back(curPartition);
            return;
        }
        string temp = "";
        for(int i=idx;i<s.length();i++) {
            temp += s[i];
            if(isPalindrome[idx][i]) {
                curPartition.push_back(temp);
                partition(s,i+1,curPartition,isPalindrome);
                curPartition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        result = {};
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        for(int i=0;i<s.length();i++) isPalindrome[i][i] = true;
        for(int i=1;i<s.length();i++) {
            for(int j=0;j+i<s.length();j++) {
                if(s[j] == s[j+i]) {
                    if(i==1) {
                        isPalindrome[j][j+i] = true;
                    }
                    else {
                        isPalindrome[j][j+i] = isPalindrome[j+1][j+i-1];
                    }
                }
            }
        }
        vector<string> temp;
        partition(s, 0, temp, isPalindrome);
        return result;
    }
};