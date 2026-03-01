class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n = len(s)
        zero = s.count('0')
        if n == k:
            if zero == 0:
                return 0
            elif zero == n:
                return 1
            else:
                return -1
        
        def ceil(x, y):
            return (x + y - 1) // y
        
        res = inf
        
        if zero % 2 == 0:
            m = max(ceil(zero, k), ceil(zero, n - k))
            if m % 2 == 1:
                m += 1
            res = min(res, m)
        if zero % 2 == k % 2:
            m = max(ceil(zero, k), ceil(n - zero, n - k))
            if m % 2 == 0:
                m += 1
            res = min(res, m)
            
        return res if res < inf else -1