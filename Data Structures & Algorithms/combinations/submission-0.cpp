class Solution {
public:
    vector<vector<int>> ans;

    void backTrack(int n, int k, int start, vector<int>& temp){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++){
            int size = temp.size();
            if(n - i + 1 < k - size) break;

            temp.push_back(i);
            backTrack(n, k, i+1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backTrack(n, k, 1, temp);
        return ans;
    }
};