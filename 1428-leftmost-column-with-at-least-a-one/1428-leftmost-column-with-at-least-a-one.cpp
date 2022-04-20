/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int minCol = INT_MAX;
        for(int i=0;i<dimension[0];i++) {
            int start = 0, end = dimension[1]-1;
            if(minCol != INT_MAX) end = minCol;
            while(start <= end) {
                int mid = start + (end-start)/2;
                if(binaryMatrix.get(i,mid) == 1) {
                    minCol = min(minCol, mid);
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        
        if(minCol == INT_MAX) minCol = -1;
        return minCol;
    }
};