class Solution {
public:
    bool PredictTheWinner(vector<int>& nums, int start, int end, int player, int score1,
                          int score2) {
        if(start > end) {
            return score1 >= score2;
        }
        
        if(player==1) {
            if(PredictTheWinner(nums,start+1,end,2,score1+nums[start],score2) 
              || PredictTheWinner(nums,start,end-1,2,score1+nums[end],score2)) {
                return true;
            }
            return false;
        }
        else {
            if(!PredictTheWinner(nums,start+1,end,1,score1,score2+nums[start]) 
              || !PredictTheWinner(nums,start,end-1,1,score1,score2+nums[end])) {
                return false;
            }
            return true;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        return PredictTheWinner(nums,0,nums.size()-1,1,0,0);
    }
};
