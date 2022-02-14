class Solution {
public:
    vector<int> arr;
    vector<int> original;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            arr.push_back(nums[i]);
            original.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return original;
    }
    
    void swap(int i, int j, vector<int> &result) {
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }
    
    vector<int> shuffle() {
        
        for(int i=0;i<arr.size();i++) {
            int j = rand() % arr.size();
            swap(i,j,arr);
        }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */