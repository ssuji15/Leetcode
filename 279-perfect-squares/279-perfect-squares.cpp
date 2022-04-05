class Solution {
public:
    int solve(int n, vector<int> &squareNumbers, unordered_map<int,int> &cache) {
        
        if(n == 1) return 1;
        if(cache.find(n) != cache.end()) return cache[n];
        auto idx = lower_bound(squareNumbers.begin(), squareNumbers.end(), n);
        
        if(*idx == n) return 1;
        
        if(*idx > n) {
            idx--;
        }
        
        if(idx == squareNumbers.begin()) {
            return 1 + solve(n-1, squareNumbers, cache);
        }
        
        int ans = INT_MAX;
        while(idx != squareNumbers.begin()) {
            int val = solve(n-*idx, squareNumbers, cache);
            if(val != INT_MAX) val++;
            ans = min(ans,val);
            idx--;
        }
        cache[n] = ans;
        return ans;
    }
    
    int numSquares(int n) {
        vector<int> squareNumbers;
        unordered_map<int,int> cache;
        int i=1;
        while(i*i <= 10000) {
            squareNumbers.push_back(i*i);
            i++;
        }
        return solve(n, squareNumbers, cache);
    }
};