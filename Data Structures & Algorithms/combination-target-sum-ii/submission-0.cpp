class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int>& candidates, vector<int>temp, int target, int sum, int index){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum > target || index> candidates.size()){
            return;
        }
        
        for(int i = index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue; // KEY LINE
            temp.push_back(candidates[i]);
            backTrack(candidates, temp, target, sum + candidates[i], i+1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        backTrack(candidates,temp,target,0,0);
        return ans;
    }
};
