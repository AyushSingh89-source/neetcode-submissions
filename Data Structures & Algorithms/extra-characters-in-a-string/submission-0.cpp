class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        vector<int> dp(n + 1, 0);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            // Case 1: s[i-1] is an extra character (not part of any valid substring)
            dp[i] = dp[i - 1] + 1;

            // Case 2: try every possible starting point j for a substring ending at i
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j); // s[j..i)
                if (dict.find(sub) != dict.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[n];
    }
};