class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        long left = 1, right = x;
        int ans = 0;

        while (left <= right) {
            long mid = left + (right - left) / 2;
            long square = mid * mid;

            if (square == x) {
                return mid;
            }
            else if (square < x) {
                ans = mid;       // store possible answer
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;  // floor value
    }
};
