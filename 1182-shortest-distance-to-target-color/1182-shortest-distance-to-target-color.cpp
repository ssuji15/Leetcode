class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size(), color1=INT_MAX, color2 = INT_MAX, color3 = INT_MAX;
        vector<vector<int>> distance(n, vector<int>(3,INT_MAX));
        
        for(int i=0;i<n;i++) {
            if(colors[i] == 1) color1 = i;
            else if(colors[i] == 2) color2 = i;
            else color3 = i;
            distance[i][0] = color1 == INT_MAX ? INT_MAX : i-color1;
            distance[i][1] = color2 == INT_MAX ? INT_MAX : i-color2;
            distance[i][2] = color3 == INT_MAX ? INT_MAX : i-color3;
        }
        color1 = INT_MAX;color2 = INT_MAX;color3 = INT_MAX;
        for(int i=n-1;i>=0;i--) {
            if(colors[i] == 1) color1 = i;
            else if(colors[i] == 2) color2 = i;
            else color3 = i;
            distance[i][0] = color1 == INT_MAX ? distance[i][0] : min(distance[i][0],color1-i);
            distance[i][1] = color2 == INT_MAX ? distance[i][1] : min(distance[i][1],color2-i);
            distance[i][2] = color3 == INT_MAX ? distance[i][2] : min(distance[i][2],color3-i);
        }
        
        vector<int> result;
        for(int i=0;i<queries.size();i++) {
            if(distance[queries[i][0]][queries[i][1]-1] == INT_MAX) {
                distance[queries[i][0]][queries[i][1]-1] = -1;
            }
            result.push_back(distance[queries[i][0]][queries[i][1]-1]);
        }
        
        return result;
        
    }
};