class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        st.push(INT_MAX);
        int res = 0;
        for(int a: arr) {
            while(st.top() <= a) {
                int val = st.top();
                st.pop();
                res += val * min(st.top(), a);
            }
            st.push(a);
        }
        
        while(st.size() > 2) {
            int val = st.top();
            st.pop(); 
            res += val * st.top();
        }
        
        return res;
    }
};