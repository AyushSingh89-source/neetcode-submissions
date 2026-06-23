class Solution {
public:
    int ans =0;
    void solve(int index, int currentXOR, vector<int>& nums){
        if(index == nums.size()){
            ans +=currentXOR;
            return;
        }

        solve(index+1,currentXOR^nums[index],nums);
        solve(index+1,currentXOR, nums);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0,0,nums);
        return ans;
    }
};