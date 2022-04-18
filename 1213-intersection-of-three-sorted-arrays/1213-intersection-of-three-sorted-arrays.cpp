class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;
        
        for(int i=0;i<arr1.size();i++) {
            auto itr1 = lower_bound(arr2.begin(), arr2.end(), arr1[i]);
            auto itr2 = lower_bound(arr3.begin(), arr3.end(), arr1[i]);
            
            if(itr1 != arr2.end() && *itr1 == arr1[i] && itr2 != arr3.end() && *itr2 == arr1[i]){
                result.push_back(arr1[i]);
            }
        }
        
        return result;
    }
};