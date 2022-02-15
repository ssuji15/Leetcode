class Solution {
public:
    int gcd(int x, int y) {
        if(x == 0) return y;
        return gcd(y%x, x);
    }
    vector<int> getSlope(vector<int> &A, vector<int> &B) {
        int x = B[1]-A[1];
        int y = B[0]-A[0];
        int temp = gcd(x,y);
        return {x/temp, y/temp};
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i=0;i<points.size();i++) {
            unordered_map<int,unordered_map<int, set<vector<int>>>> slope;
            for(int j=i+1;j<points.size();j++) {
                vector<int> temp= getSlope(points[i], points[j]);
                slope[temp[0]][temp[1]].insert(points[i]);
                slope[temp[0]][temp[1]].insert(points[j]);
                if(slope[temp[0]][temp[1]].size() > ans) {
                    ans = slope[temp[0]][temp[1]].size();
                }
            }
        }
        return ans;
    }
};