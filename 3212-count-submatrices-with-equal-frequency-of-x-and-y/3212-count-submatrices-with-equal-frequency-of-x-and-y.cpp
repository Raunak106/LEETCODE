class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;

        // prefix sum matrix for value
        vector<vector<int>> pref(m, vector<int>(n, 0));
        // prefix count of X
        vector<vector<int>> xpref(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                int val = 0;
                if(grid[i][j] == 'X') val = 1;
                else if(grid[i][j] == 'Y') val = -1;

                int xval = (grid[i][j] == 'X') ? 1 : 0;

                pref[i][j] = val;
                xpref[i][j] = xval;

                if(i > 0) {
                    pref[i][j] += pref[i-1][j];
                    xpref[i][j] += xpref[i-1][j];
                }
                if(j > 0) {
                    pref[i][j] += pref[i][j-1];
                    xpref[i][j] += xpref[i][j-1];
                }
                if(i > 0 && j > 0) {
                    pref[i][j] -= pref[i-1][j-1];
                    xpref[i][j] -= xpref[i-1][j-1];
                }

                // check conditions
                if(pref[i][j] == 0 && xpref[i][j] > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};