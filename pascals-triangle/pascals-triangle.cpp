class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        
        for(int i=1;i<numRows;i++) {
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<result[result.size()-1].size();j++) {
                temp.push_back(result[result.size()-1][j] + result[result.size()-1][j-1]);
            }
            temp.push_back(1);
            result.push_back(temp);
        }
        
        return result;
    }
};