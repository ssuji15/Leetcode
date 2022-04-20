/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int curIdx = 1, prevIdx = INT_MAX, start, end;
        
        while(1) {
            int value = reader.get(curIdx);
            if(value == target) return curIdx;
            else if(value == INT_MAX) {
                start = prevIdx;
                if(start == INT_MAX) start = 0;
                end = curIdx;
                break;
            }
            else if(target < value) {
                start = prevIdx;
                if(start == INT_MAX) start = 0;
                end = curIdx;
                break;
            }
            else {
                prevIdx = curIdx;
                curIdx = curIdx * 2;
            }
        }
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int value = reader.get(mid);
            if(value == target) {
                return mid;
            }
            else if(value < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return -1;
        
        
        
    }
};