class Solution {
public:
    void updateMaxDegrees(int &firstMax, int &firstMaxCount, int &secondMax, int &secondMaxCount, int value) {
        if(value > firstMax) {
            secondMax = firstMax;
            secondMaxCount = firstMaxCount;
            firstMax = value;
            firstMaxCount = 1;
        }
        else if(value == firstMax) {
            firstMaxCount++;
        }
        else if(value > secondMax) {
            secondMax = value;
            secondMaxCount = 1;
        }
        else if(value == secondMax) {
            secondMaxCount++;
        }
    }
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> degree(n, 0);
        int firstMax = INT_MIN, secondMax = INT_MIN, firstMaxCount = 0, secondMaxCount = 0;
        for(int i=0;i<roads.size();i++) {
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }
        for(int i=0;i<n;i++) {
            updateMaxDegrees(firstMax, firstMaxCount, secondMax, secondMaxCount, degree[i]);
        }
        int result;
        if(firstMaxCount > 1 ) {
            int count = 0;
            for(int i=0;i<roads.size();i++) {
                if(degree[roads[i][0]] == firstMax && degree[roads[i][1]] == firstMax) {
                    count++;
                }
            }
            int maxEdgesPossible = firstMaxCount * (firstMaxCount-1) / 2;
            result = 2 * firstMax + (count == maxEdgesPossible ? -1 : 0);
        } else if(secondMaxCount > 0) {
            int count = 0;
            for(int i=0;i<roads.size();i++) {
                if(degree[roads[i][0]] == firstMax && degree[roads[i][1]] == secondMax) {
                    count++;
                }
                if(degree[roads[i][0]] == secondMax && degree[roads[i][1]] == firstMax) {
                    count++;
                }
            }
            result = firstMax + secondMax + (count == secondMaxCount ? -1 : 0);
        }
        return result;
    }
};
