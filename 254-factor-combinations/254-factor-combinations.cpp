class Solution {
public:
    vector<vector<int>> result;
    void findFactors(int i, int factor, vector<int> &temp) {

        if(factor == 1) {
            result.push_back(temp);
            return;
        }
        
        for(int j=i;j<=factor;j++) {
            if(factor%j == 0) {
                temp.push_back(j);
                findFactors(j, factor/j, temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        result = {};
        for(int i=2;i<n;i++) {
            if(n%i == 0) {
                vector<int> temp = {i};
                findFactors(i,n/i,temp);
            }
        }
        return result;
    }
};