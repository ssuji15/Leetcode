class Solution {
public:
    static bool myCompare(vector<int> &A, vector<int> &B) {
        if(A[0] == B[0]) return A[1] < B[1];
        return A[0] < B[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), myCompare);
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] <= result[result.size()-1][1]) {
                result[result.size()-1][1] = max(result[result.size()-1][1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};