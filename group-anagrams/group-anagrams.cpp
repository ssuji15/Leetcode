class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> cache;
        vector<vector<string>> result;
        for(int i=0;i<strs.size();i++) {
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            cache[temp].push_back(strs[i]);
        }
        
        for(auto itr: cache) {
            result.push_back(itr.second);
        }
        
        return result;
    }
};