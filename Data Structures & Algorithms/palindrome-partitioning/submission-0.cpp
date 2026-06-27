class Solution {
public:
    bool isPalin(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void backtrack(string& s, int index, vector<string>& current, vector<vector<string>>& result) {
        if (index == s.size()) {
            result.push_back(current);
            return;
        }

        for (int j = index; j < s.size(); j++) {
            if (isPalin(s, index, j)) {
                current.push_back(s.substr(index, j - index + 1));
                backtrack(s, j + 1, current, result);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
};