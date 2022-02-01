class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<vector<int>> pq;
        vector<int> result;
        
        for(int i=0;i<k-1;i++) {
            pq.push({nums[i],i});
        }
        
        for(int i=k-1;i<nums.size();i++) {

            while(!pq.empty() && pq.top()[1] < (i-(k-1))) {
                pq.pop();
            }
            
            pq.push({nums[i],i});
            
            result.push_back(pq.top()[0]);
        }
        
        return result;
    }
};
