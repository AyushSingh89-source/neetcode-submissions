class Solution {
public:
    vector<vector<int>> ans;
    void backTrack(vector<int>& nums,vector<int> temp, int target, int sum, int index){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum > target || index >= nums.size()){
            return;
        }
        temp.push_back(nums[index]);
        backTrack(nums, temp, target, sum+ nums[index], index);

        temp.pop_back();
        backTrack(nums,temp, target, sum, index + 1);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        backTrack(nums, temp, target, 0, 0);
        return ans;
    }
};
