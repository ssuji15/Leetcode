class Solution {
public:
    struct MyCompare {
        public: 
        bool operator() (vector<int> &A, vector<int> &B) {
            return A[0] < B[0];
        }
    };
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), MyCompare());
        vector<int> lengths(pairs.size(), 1);
        int ans = 1;
        for(int i=1;i<pairs.size();i++) {
            for(int j=0;j<i;j++) {
                if(pairs[j][1] < pairs[i][0]) {
                    lengths[i] = max(lengths[i], 1 + lengths[j]);
                    ans = max(ans, lengths[i]);
                }
            }
        }
        return ans;
    }
};