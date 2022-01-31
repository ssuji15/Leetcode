class Solution {
public:
    string decodeString(int &i, string &s) {
        
        string res = "";
        int num = 0;
        while(i < s.length() && s[i] != ']') {
            
            if(s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            }
            else if(s[i] >= '0' && s[i] <= '9') {
                num = (num * 10) + (s[i] - '0'); 
            }
            else if(s[i] == '[') {
                i++;
                string str = decodeString(i, s);
                for(int j=0;j<num;j++) {
                    res += str;
                }
                num = 0;
            }
            i++;
        }
        return res;
    }

    string decodeString(string s) {
        int i=0;
        return decodeString(i,s);
    }
};