class Solution {
public:
    
    long long calc(long long T, int t){
        long long val = (2*T) / t;
        long long x = (sqrt(1 + 4*val) - 1) / 2;
        return x;
    }

    bool can(long long T, int mountainHeight, vector<int>& workerTimes){
        long long total = 0;

        for(int t : workerTimes){
            total += calc(T, t);
            if(total >= mountainHeight) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while(left <= right){
            long long mid = (left + right) / 2;

            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }

        return ans;
    }
};