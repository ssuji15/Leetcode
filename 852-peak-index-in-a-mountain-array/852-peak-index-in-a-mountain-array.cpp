class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(mid == 0) {
                start = mid+1;
            }
            else if(mid == arr.size()-1) {
                end = mid-1;
            }
            else if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
                return mid;
            }
            else if(arr[mid-1] < arr[mid] && arr[mid+1] > arr[mid]) {
                start = mid+1;
            }
            else if(arr[mid-1] > arr[mid] && arr[mid+1] < arr[mid]) {
                end = mid-1;
            }
        }
        return -1;
    }
};