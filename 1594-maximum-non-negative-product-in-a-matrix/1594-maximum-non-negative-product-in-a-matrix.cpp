class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        const long long MOD = 1e9 + 7;
        
        // dp[i][j] = {max_product, min_product}
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n));
        
        dp[0][0] = {grid[0][0], grid[0][0]};
        
        // First row
        for (int j = 1; j < n; j++) {
            long long val = grid[0][j];
            dp[0][j].first = dp[0][j-1].first * val;
            dp[0][j].second = dp[0][j-1].second * val;
        }
        
        // First column
        for (int i = 1; i < m; i++) {
            long long val = grid[i][0];
            dp[i][0].first = dp[i-1][0].first * val;
            dp[i][0].second = dp[i-1][0].second * val;
        }
        
        // Fill rest of grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                
                long long a = dp[i-1][j].first * val;
                long long b = dp[i-1][j].second * val;
                long long c = dp[i][j-1].first * val;
                long long d = dp[i][j-1].second * val;
                
                dp[i][j].first = max({a, b, c, d});
                dp[i][j].second = min({a, b, c, d});
            }
        }
        
        long long result = dp[m-1][n-1].first;
        
        if (result < 0) return -1;
        return result % MOD;
    }
};