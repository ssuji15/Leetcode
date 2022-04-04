class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> rightDP(m, vector<int>(n, 0));
        vector<vector<int>> bottomDP(m, vector<int>(n, 0));

        for(int i=m-1;i>=0;i--) {
            int right=0;
            for(int j=n-1;j>=0;j--) {
                if(grid[i][j] == 'W') {
                    right = 0;
                    if(i-1 >= 0) {
                        bottomDP[i-1][j] = 0;
                    }
                }
                else if(grid[i][j] == 'E') {
                    right++;
                    if(i-1 >= 0) {
                        bottomDP[i-1][j] = bottomDP[i][j] + 1;
                    }
                }
                else if(grid[i][j] == '0') {
                    rightDP[i][j] = right;
                    if(i-1 >= 0) {
                        bottomDP[i-1][j] = bottomDP[i][j];
                    }
                }
            }
        }
        int ans = 0;
        vector<int> top(n, 0);
        for(int i=0;i<m;i++) {
            int left = 0;
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '0') {
                    int curCount = left + top[j] + rightDP[i][j] + bottomDP[i][j];
                    ans = max(ans, curCount);
                }
                else if(grid[i][j] == 'E') {
                    left++;
                    top[j]++;
                }
                else if(grid[i][j] == 'W') {
                    left = 0;
                    top[j] = 0;
                }
            }
        }
        
        return ans;
    }
};

