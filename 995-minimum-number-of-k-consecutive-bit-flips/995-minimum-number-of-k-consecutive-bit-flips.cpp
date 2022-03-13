class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int> q;
        int res = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] == (q.size() % 2 == 0 ? 0 : 1)) {
                res++;
                if(i+k-1 >= nums.size()) return -1;
                q.push(i+k-1);
            }
            while(!q.empty() && q.front() <= i) q.pop();
        }
        return res;
    }
};