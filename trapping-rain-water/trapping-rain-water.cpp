class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> maxHeightRight(height.size());
        
        int curMaxHeight = height[height.size()-1], ans=0;
        maxHeightRight[height.size()-1] = curMaxHeight;
        
        for(int i=height.size()-2; i>=0; i--) {
            maxHeightRight[i] = max(maxHeightRight[i+1], height[i]);
        }
        
        curMaxHeight = height[0];
        for(int i=0;i<height.size();i++) {
            
            int water = min(curMaxHeight, maxHeightRight[i]) - height[i];
            
            if(water > 0) {
                ans += water;
            }
            
            curMaxHeight = max(curMaxHeight, height[i]);
        }
        
        return ans;
    }
};