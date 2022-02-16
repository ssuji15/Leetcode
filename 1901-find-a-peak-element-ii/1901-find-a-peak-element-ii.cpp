class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size(), n=mat.size(), m=mat[0].size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            int maxRow = 0;
            for(int i=0;i<mat.size();i++) {
                if(mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }
            
            if((mid == 0 || (mat[maxRow][mid] > mat[maxRow][mid-1])) && 
              (mid==m-1 || mat[maxRow][mid] > mat[maxRow][mid+1])) {
                return {maxRow, mid};
            }
            else if(mid-1 >= 0 && mat[maxRow][mid-1] > mat[maxRow][mid]) {
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return {-1,-1};
    }
};

