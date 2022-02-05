class Solution {
public:
    int reverse(int x) {
        
        long long ans = 0;
        bool isNegative = false;
        
        if(x < 0) {
            if(x * -1L > INT_MAX) return 0;
            isNegative = true;
            x = x * -1;
        }
        
        while(x!=0) {
            ans = ans * 10 + (x%10);
            x = x/10;
        }
        
        if(isNegative) {
            ans = ans * -1;
        }
        
        if(ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        
        return ans;
    }
};