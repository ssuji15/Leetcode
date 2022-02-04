class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> comb(target+1);
        
        comb[0] = {{}}; 
        
        for(int i=0;i<candidates.size();i++) {
            int value = candidates[i];
            for(int j=1;j<=target;j++) {
                if(j-value >= 0) {
                    vector<vector<int>> temp = comb[j-value];
                    for(int k=0;k<temp.size();k++) {
                        vector<int> temp1 = temp[k];
                        temp1.push_back(value);
                        comb[j].push_back(temp1);
                    }
                }
            }
        }
        
        return comb[target];
    }
};