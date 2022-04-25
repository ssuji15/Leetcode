class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        vector<vector<int>> recMap(101);
        vector<int> result(points.size(), 0);
        for(int i=0;i<rectangles.size();i++) {
            recMap[rectangles[i][1]].push_back(rectangles[i][0]);
        }
        
        for(int i=0;i<101;i++) {
            sort(recMap[i].begin(), recMap[i].end());
        }
        
        for(int  i=0;i<points.size();i++) {
            for(int j=points[i][1];j<101;j++) {
                result[i] += recMap[j].end() - lower_bound(recMap[j].begin(), recMap[j].end(), points[i][0]);
            }
        }
        return result;
    }
};