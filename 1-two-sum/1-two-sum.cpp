class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> numbers;
        for(int i=0;i<nums.size();i++) {
            numbers.push_back({nums[i], i});
        }
        
        sort(numbers.begin(), numbers.end());
        
        int start = 0, end = numbers.size()-1;
        while(start < end) {
            int sum = numbers[start].first + numbers[end].first;
            if(sum == target) {
                return {numbers[start].second, numbers[end].second};
            }
            else if(sum < target) {
                start++;
            }
            else {
                end--;
            }
        }
        return {-1,-1};
    }
};