class Solution {
public:
    struct MyCompare {
        bool operator()(vector<int> &A, vector<int> &B) {
            return A[0] < B[0];
        }
    };
    
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        
        sort(slots1.begin(), slots1.end(), MyCompare());
        sort(slots2.begin(), slots2.end());
        
        for(int i=0,j=0;i<slots1.size() && j<slots2.size();) {
            
            int start = max(slots1[i][0], slots2[j][0]);
            int end = min(slots1[i][1], slots2[j][1]);
            
            if(end - start >= duration) {
                return {start, start+duration};
            }
            
            if(slots1[i][1] == slots2[j][1]) i++,j++;
            else if(slots1[i][1] > slots2[j][1]) j++;
            else i++;
        }
        
        return {};
    }
};