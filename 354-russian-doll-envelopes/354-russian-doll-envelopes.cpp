class Solution {
public:
    struct Mycompare {
      bool operator()(const vector<int> &A, const vector<int> &B) {
          if(A[0] == B[0]) {
              return A[1] > B[1];
          }
          return A[0] < B[0];
      }  
    };
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), Mycompare());
        vector<int> heights, temp;
        for(int i=0;i<envelopes.size();i++) {
            heights.push_back(envelopes[i][1]);
        }
        temp.push_back(heights[0]);
        for(int i=1;i<heights.size();i++) {
            if(temp[temp.size()-1] < heights[i]) temp.push_back(heights[i]);
            else {
                int idx = lower_bound(temp.begin(), temp.end(), heights[i]) - temp.begin();
                temp[idx] = heights[i];
            }
        }
        return temp.size();
    }
};