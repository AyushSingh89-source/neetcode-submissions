class Solution {
public:
    bool backTrack(vector<int>& matchsticks, int side, int index, vector<int>& sides){
        if(index == matchsticks.size()){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if(sides[i] + matchsticks[index] <= side){
                sides[i] += matchsticks[index];
                
                if(backTrack(matchsticks, side, index+1, sides)){
                    return true;
                }
                
                sides[i] -= matchsticks[index];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        for(int i=0; i<matchsticks.size(); i++){
            sum += matchsticks[i];
        }

        if(sum%4 != 0){
            return false;
        }

        int side = sum/4;
        vector<int> sizes(4,0);

        sort(matchsticks.begin(),matchsticks.end());
        return backTrack(matchsticks, side, 0, sizes);
    }
};