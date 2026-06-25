class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums, vector<int>& temp, vector<bool>& visited){
        if(nums.size() == temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(visited[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i]= true;

            temp.push_back(nums[i]);
            backTrack(nums, temp, visited);
            temp.pop_back();

            visited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        backTrack(nums,temp,visited);

        return ans;
    }
};