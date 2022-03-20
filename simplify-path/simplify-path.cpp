class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        st.push("/");
        string temp = "";
        for(int i=0;i<path.length();i++) {
            if(path[i] == '/') {
                if(temp.compare("..") == 0) {
                    if(st.size() > 1) st.pop();
                }
                else if(temp.compare(".") == 0 || temp.compare("") == 0 ) {
                    
                }
                else {
                    st.push(temp);
                }
                temp = "";
            }
            else {
                temp += path[i];
            }
        }
        
        if(temp.compare("..") == 0) {
            if(st.size() > 1) st.pop();
        }
        else if(temp.compare(".") == 0 || temp.compare("") == 0 ) {

        }
        else {
            st.push(temp);
        }
        
        string result = "";
        while(st.size() > 1) {
            string word = st.top();
            st.pop();
            reverse(word.begin(), word.end());
            result += word;
            result += "/";
        }
        if(result == "") {
            result += "/";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};