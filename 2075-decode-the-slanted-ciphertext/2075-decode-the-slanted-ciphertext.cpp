class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 0 || encodedText.empty()) return "";

        int n = encodedText.size();
        int col = n / rows;

        vector<vector<char>> mat(rows, vector<char>(col));

        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                mat[i][j] = encodedText[k++];
            }
        }

        string s = "";

        for (int j = 0; j < col; j++) {
            int rr = 0, cc = j;
            while (rr < rows && cc < col) {
                s += mat[rr][cc];
                rr++;
                cc++;
            }
        }

        // Remove trailing spaces
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }

        return s;
    }
};