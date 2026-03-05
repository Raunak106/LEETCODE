class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int start0 = 0, start1 = 0;

        for(int i = 0; i < n; i++){
            // pattern starting with 0 -> 010101
            if(s[i] != (i % 2 == 0 ? '0' : '1'))
                start0++;

            // pattern starting with 1 -> 101010
            if(s[i] != (i % 2 == 0 ? '1' : '0'))
                start1++;
        }

        return min(start0, start1);
    }
};