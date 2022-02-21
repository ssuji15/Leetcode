class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> sortedIndexes;
        vector<int> result;
        for(int i=0;i<nums.size();i++) {
            while(!sortedIndexes.empty() && sortedIndexes.front() < (i-(k-1))) {
                sortedIndexes.pop_front();
            }
            
            while(!sortedIndexes.empty() && nums[i] > nums[sortedIndexes.back()]) {
                sortedIndexes.pop_back();
            }
            
            sortedIndexes.push_back(i);
            if(i-(k-1)>=0) {
                result.push_back(nums[sortedIndexes.front()]);
            }
        }
        return result;
    }
};