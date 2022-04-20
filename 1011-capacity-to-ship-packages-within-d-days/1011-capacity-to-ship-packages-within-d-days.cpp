class Solution {
public:
    bool canSplit(vector<int> &weights, int days, int maxWeight) {
        
        int sum  = 0, count = 1;
        
        for(int i=0;i<weights.size();i++) {
            if(sum + weights[i] <= maxWeight) {
                sum += weights[i];
            }
            else {
                sum = weights[i];
                count++;
            }
        }
        return count <= days && sum <= maxWeight;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int minWeight = INT_MIN, sumWeight = 0, start , end, ans = INT_MAX;
        for(int i=0;i<weights.size();i++) {
            sumWeight += weights[i];
            minWeight = max(minWeight, weights[i]);
        }
        
        start = minWeight, end = sumWeight;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            if(canSplit(weights, days, mid)) {
                ans = mid;
                end = mid-1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};