class Solution {
public:
    bool canCut(vector<int>& sweetness, int k, int maxVal, vector<int> &prefixSum) {
        int sum = 0,i;
        for(i=0;i<sweetness.size();i++) {
            sum += sweetness[i];
            if(sum >= maxVal) {
                sum = 0;
                k--;
            }
            if(k==0) break;
        }
        
        if(i>=sweetness.size()-1) return false;
        return prefixSum[sweetness.size()-1] - prefixSum[i] >= maxVal;
        
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        vector<int> prefixSum(sweetness.size(), 0);
        prefixSum[0] = sweetness[0];
        int start = 0, end = 0, ans=0;
        
        for(int i=1;i<sweetness.size();i++) {
            prefixSum[i] = prefixSum[i-1] + sweetness[i];
            end = prefixSum[i];
        }
        
        if(k==0) return end;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(canCut(sweetness,k,mid,prefixSum)) {
                ans = mid;
                start = mid+1;
            }
            else {
                end = mid-1;
            }
        }
        return ans;
    }
};