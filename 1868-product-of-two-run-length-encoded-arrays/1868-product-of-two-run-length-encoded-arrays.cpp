class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        
        vector<vector<int>> result;
        for(int i=0,j=0;i<encoded1.size() && j<encoded2.size();) {
            
            int prod = encoded1[i][0] * encoded2[j][0];
            int freq = min(encoded1[i][1], encoded2[j][1]);
            
            if(result.size() == 0) {
                result.push_back({prod, freq});
            } 
            else {
                
                if(result[result.size()-1][0] == prod) {
                    result[result.size()-1][1] += freq;
                }
                else {
                    result.push_back({prod, freq});
                }
            }
            if(encoded1[i][1] == encoded2[j][1]) {
                i++;
                j++;
            }
            else if(encoded1[i][1] > encoded2[j][1]) {
                encoded1[i][1] -= encoded2[j][1];
                j++;
            }
            else {
                encoded2[j][1] -= encoded1[i][1];
                i++;
            }
        }
        return result;
    }
};