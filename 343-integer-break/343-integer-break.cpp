class Solution {
public:

    int integerBreak(int n) {
        vector<int> arr(n+1,0);
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 1;
        
        for(int i=3;i<=n;i++) {
            for(int j=1;j<i;j++) {
                int remaining = i-j;
                arr[i] = max(arr[i], max(j*(remaining), j * arr[remaining]));
            }
        }
        return arr[n];
    }
};