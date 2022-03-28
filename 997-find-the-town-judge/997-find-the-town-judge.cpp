class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n,0);
        vector<int> outGoing(n,0);
        for(int i=0;i<trust.size();i++) {
            outGoing[trust[i][0]-1]++;
            trustCount[trust[i][1]-1]++;
        }
        
        for(int i=0;i<n;i++) {
            if(outGoing[i] == 0 && trustCount[i] == n-1) return i+1;
        }
        return -1;
    }
};