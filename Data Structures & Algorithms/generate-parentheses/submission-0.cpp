class Solution {
public:
    vector<string> ans;
    unordered_map<string,int> mp;

    void backTrack(int n,int open, int close, string temp){
        if(temp.size() == 2*n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            backTrack(n,open + 1, close, temp + "(");
        }
        if(close<open){
            backTrack(n,open, close + 1, temp + ")");
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string temp;
        backTrack(n, 0, 0, temp);
        return ans;
    }
};
