/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n, mid, curGuess;
        do {
            mid = low + (high-low)/2;
            curGuess = guess(mid);
            if(curGuess == 0) return mid;
            else if(curGuess == -1) {
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        while(curGuess != 0);
        return -1;
    }
};