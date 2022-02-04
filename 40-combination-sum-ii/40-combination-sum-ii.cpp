class Solution {
public:
    vector<vector<int>> result;
    bool findComb(int idx, vector<int>& candidates, int target, vector<int> &res) {
        
        if(target == 0) {
            result.push_back(res);
            return true;
        }

        if(target < 0) return true;
        
        for(int i=idx;i<candidates.size();i++) {
            if(i != idx && candidates[i] == candidates[i-1]) continue;
            res.push_back(candidates[i]);
            bool shouldBreak = findComb(i+1, candidates, target-candidates[i], res);
            res.pop_back();
            if(shouldBreak) break;
        }
        
        return false;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        result = {};
        vector<int> temp;
        findComb(0, candidates, target, temp);
        return result;
    }
};

