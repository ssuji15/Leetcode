class Solution {
public:
    int findCurArea(vector<int> &heights) {
        stack<int> st;
        st.push(-1);
        int maxArea = 0,i;
        for(i=0;i<heights.size();i++) {
            while(st.top() != -1 && heights[i] < heights[st.top()]) {
                int idx = st.top();
                st.pop();
                int area = heights[idx] * (i-st.top()-1);
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while(st.top() != -1) {
            int idx = st.top();
            st.pop();
            int area = heights[idx] * (i-st.top()-1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> value(matrix[0].size(), 0);
        int ans = 0;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                if(matrix[i][j] == '1') {
                    value[j]++;
                }
                else {
                    value[j] = 0;
                }
            }
            int area = findCurArea(value);
            ans = max(ans, area);
        }
        return ans;
    }
};
