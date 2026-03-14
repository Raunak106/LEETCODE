class Solution {
public:
    void dfs(int n, string &curr, int &k, string &ans) {
        if(curr.size() == n) {
            k--;
            if(k == 0) ans = curr;
            return;
        }

        for(char c : {'a','b','c'}) {
            if(curr.empty() || curr.back() != c) {
                curr.push_back(c);
                dfs(n, curr, k, ans);
                curr.pop_back();

                if(k == 0) return;
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string ans = "";

        dfs(n, curr, k, ans);
        return ans;
    }
};