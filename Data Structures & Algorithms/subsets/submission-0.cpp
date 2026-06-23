class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums,vector<int> temp,int index){
        if(index == nums.size()){
            return ans.push_back(temp);
        }
        temp.push_back(nums[index]);
        backtrack(nums,temp,index+1);

        temp.pop_back();
        backtrack(nums,temp,index+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums,temp,0);
        return ans;
    }
};
