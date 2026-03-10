class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;

        vector<vector<long long>> dp0(zero+1, vector<long long>(one+1,0));
        vector<vector<long long>> dp1(zero+1, vector<long long>(one+1,0));

        for(int i=1;i<=min(limit,zero);i++)
            dp0[i][0]=1;

        for(int j=1;j<=min(limit,one);j++)
            dp1[0][j]=1;

        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){

                dp0[i][j] = dp1[i-1][j];
                if(i-limit-1>=0)
                    dp0[i][j] = (dp0[i][j] - dp1[i-limit-1][j] + MOD)%MOD;

                dp0[i][j] = (dp0[i][j] + dp0[i-1][j])%MOD;

                dp1[i][j] = dp0[i][j-1];
                if(j-limit-1>=0)
                    dp1[i][j] = (dp1[i][j] - dp0[i][j-limit-1] + MOD)%MOD;

                dp1[i][j] = (dp1[i][j] + dp1[i][j-1])%MOD;
            }
        }

        long long ans = (dp0[zero][one] + dp1[zero][one]) % MOD;

        return ans;
    }
};