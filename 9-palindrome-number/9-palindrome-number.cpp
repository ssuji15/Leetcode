class Solution {
public:
    bool isPalindrome(int x) {
        long long temp = x, reversedNum = 0;
        while(temp != 0) {
            reversedNum = reversedNum * 10 + temp % 10;
            temp = temp / 10;
        }
        if(x < 0) reversedNum = reversedNum * -1;
        return x == reversedNum;
    }
};