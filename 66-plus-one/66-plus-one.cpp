class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--) {
            int value = digits[i] + carry;
            result.push_back(value%10);
            carry = value/10;
        }
        if(carry != 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};