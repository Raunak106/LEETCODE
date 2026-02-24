public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int low = 1;
        int high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;   // prevents overflow
            int result = guess(mid);
            
            if (result == 0) {
                return mid;           // found the number
            } else if (result == -1) {
                high = mid - 1;       // guess was too high
            } else {
                low = mid + 1;        // guess was too low
            }
        }
        
        return -1; // never reached
    }
}
