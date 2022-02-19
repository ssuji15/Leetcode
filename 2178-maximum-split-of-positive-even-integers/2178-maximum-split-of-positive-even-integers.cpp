class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2) return {};
        vector<long long> result;
        long long curSum = 0,i=2;
        
        while(curSum + i <= finalSum) {
            result.push_back(i);
            curSum += i;
            i+=2;
        }
        
        result[result.size()-1] = result[result.size()-1] + (finalSum - curSum);
        return result;
    }
};