class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> temp;
        for(int i=0;i<pairs.size();i++) {
            temp.push_back({pairs[i][1], pairs[i][0]});
        }
        sort(temp.begin(), temp.end());
        int ans = 1;
        int cur = temp[0].first;
        for(int i=1;i<temp.size();i++) {
            if(temp[i].second > cur) {
                ans++;
                cur = temp[i].first;
            }
        }
        return ans;
    }
};