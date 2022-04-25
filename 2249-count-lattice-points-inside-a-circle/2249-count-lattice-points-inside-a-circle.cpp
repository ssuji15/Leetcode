class Solution {
public:
    
    int countLatticePoints(vector<vector<int>>& circles) {
        
        set<pair<int,int>> points;
        
        for(int i=0;i<circles.size();i++) {
            int X=circles[i][0], Y = circles[i][1], r = circles[i][2];
            for(int x=-r;x<=r;x++) {
                for(int y=-r;y<=r;y++) {
                    if((x*x) + (y*y) <= r*r) {
                        points.insert({X+x, Y+y});
                    }
                }
            }
        }
        
        return points.size();
    }
};