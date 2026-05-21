class Solution { 
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < nums.size() - 2; i++) {
            // Correction 1: Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int start = i + 1;
            int last = nums.size() - 1;
            
            while (start < last) {
                int sum = nums[i] + nums[start] + nums[last]; // Correction 3: Use direct sum
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[start], nums[last]});
                    
                    // Correction 2: Skip duplicate values for start and last pointers
                    while (start < last && nums[start] == nums[start + 1]) start++;
                    while (start < last && nums[last] == nums[last - 1]) last--;
                    
                    start++;
                    last--;
                } 
                else if (sum > 0) {
                    last--; // Sum is too large, move the right pointer left
                } 
                else {
                    start++; // Sum is too small, move the left pointer right
                }
            }
        }
        return ans;
    }
};