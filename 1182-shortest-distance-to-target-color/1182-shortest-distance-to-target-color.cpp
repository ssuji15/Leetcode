class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> distances(colors.size(), vector<int>(3,INT_MAX));
        
        int color1 = INT_MAX, color2 = INT_MAX, color3 = INT_MAX;
        for(int i=0;i<colors.size();i++) {
            if(colors[i] == 1) {
                color1 = i;
            }
            else if(colors[i] == 2) {
                color2 = i;
            }
            else if(colors[i] == 3) {
                color3 = i;
            }

            distances[i][0] = color1 == INT_MAX ? INT_MAX : i-color1;
            distances[i][1] = color2 == INT_MAX ? INT_MAX : i-color2;
            distances[i][2] = color3 == INT_MAX ? INT_MAX : i-color3;
        }
        color1 = INT_MAX, color2 = INT_MAX, color3 = INT_MAX;
        for(int i=colors.size()-1;i>=0;i--) {
            if(colors[i] == 1) {
                color1 = i;
            }
            else if(colors[i] == 2) {
                color2 = i;
            }
            else if(colors[i] == 3) {
                color3 = i;
            }
            distances[i][0] = min(distances[i][0],color1 == INT_MAX ? INT_MAX : color1-i);
            distances[i][1] = min(distances[i][1],color2 == INT_MAX ? INT_MAX : color2-i);
            distances[i][2] = min(distances[i][2],color3 == INT_MAX ? INT_MAX : color3-i);
        }
        
        vector<int> result;
        for(int i=0;i<queries.size();i++) {
            int idx = queries[i][0];
            int color = queries[i][1]-1;
            if(distances[idx][color] == INT_MAX) {
                distances[idx][color] = -1;
            }
            result.push_back(distances[idx][color]);
        }
        
        return result;
        
    }
};