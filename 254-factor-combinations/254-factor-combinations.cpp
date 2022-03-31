class Solution {
public:
    unordered_map<int, vector<vector<int>>> cache;
    vector<vector<int>> getFactors(int n) {
        if(n <= 3) return {};
        if(cache.find(n) != cache.end()) return cache[n];
        int val = ceil(sqrt(n));
        set<vector<int>> result;
        for(int i=2;i<=val;i++) {
            if(n%i==0) {
                vector<vector<int>> temp = getFactors(n/i);
                temp.push_back({n/i});
                for(int j=0;j<temp.size();j++) {
                    temp[j].push_back(i);
                    sort(temp[j].begin(), temp[j].end());
                    result.insert(temp[j]);
                }
            }
        }
        vector<vector<int>> res(result.begin(), result.end());
        cache[n] = res;
        return res;
    }
};