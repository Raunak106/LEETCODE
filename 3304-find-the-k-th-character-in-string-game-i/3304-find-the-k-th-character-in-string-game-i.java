class Solution {
    public char kthCharacter(long k) {
        long len = 1;

        while (len < k) {
            len *= 2;
        }

        int shift = 0;

        while (len > 1) {
            long half = len / 2;

            if (k > half) {
                k = k - half;
                shift++;
            }
            len = half;
        }

        return (char) ('a' + shift % 26);
    }
}
