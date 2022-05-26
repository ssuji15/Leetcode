class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1,j=m+n-1;i>=0;i--,j--) {
            nums1[j] = nums1[i];
        }
        
        int arr1Idx = n, arr2Idx = 0, resultIdx=0;
        while(arr1Idx < m+n && arr2Idx < n) {
            if(nums1[arr1Idx] < nums2[arr2Idx]) {
                nums1[resultIdx++] = nums1[arr1Idx++];
            }
            else {
                nums1[resultIdx++] = nums2[arr2Idx++];
            }
        }
        
        while(arr1Idx < m+n) {
            nums1[resultIdx++] = nums1[arr1Idx++];
        }
        
        while(arr2Idx < n) {
            nums1[resultIdx++] = nums2[arr2Idx++];
        }
    }
};