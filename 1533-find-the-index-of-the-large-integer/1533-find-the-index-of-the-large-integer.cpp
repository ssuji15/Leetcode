/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int start = 0, end = reader.length()-1;
        
        while(start < end) {
            
            int mid = start + (end-start)/2, value;
            if((end-start) % 2 == 0) {
                value = reader.compareSub(start,mid,mid,end);
            }
            else {
                value = reader.compareSub(start,mid,mid+1,end);
            }
            
            if(value == 1) {
                end = mid;
            } 
            else if(value == -1) {
                start = mid+1;
            }
            else {
                return mid;
            }
        }
        
        return start;
    }
};
