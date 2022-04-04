class Solution {
public:
    unordered_map<int,int> dp;
    int numTrees(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(dp.find(n) != dp.end()) return dp[n];
        int ans = 0;
        for(int i=0;i<n;i++) {
            int left = numTrees(i);
            int right = numTrees(n-i-1);
            ans += (left == 0 ? 1 : left)  * (right == 0 ? 1 : right);  
        }
        dp[n] = ans;
        return ans;
    }
};