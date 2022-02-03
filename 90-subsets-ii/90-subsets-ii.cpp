class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result, temp;
        
        result.push_back({});
        result.push_back({nums[0]});
        temp = {{nums[0]}};
        
        for(int i=1;i<nums.size();i++) {

            vector<vector<int>> prevTemp;
            if(nums[i] == nums[i-1]) {
                for(int j=0;j<temp.size();j++) {
                    vector<int> cur = temp[j];
                    cur.push_back(nums[i]);
                    prevTemp.push_back(cur);
                    result.push_back(cur);
                }
                temp = prevTemp;
            }
            else {
                int size = result.size();
                for(int j=0;j<size;j++) {
                    vector<int> cur = result[j];
                    cur.push_back(nums[i]);
                    result.push_back(cur);
                    prevTemp.push_back(cur);
                }
                temp = prevTemp;
            }
        }
        
        return result;
    }
};