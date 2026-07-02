class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int > score(n+1, 0);

        for(int i=0; i<trust.size(); i++){
            int a = trust[i][0];
            int b = trust[i][1];

            score[a]--; score[b]++;
        }

        for(int i=0; i<=n; i++){
            if(score[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};