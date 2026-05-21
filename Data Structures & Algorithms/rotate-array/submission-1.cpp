class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k is greater than n
        
        vector<int> ans;
        
        // 1. Get the elements that will wrap around to the front
        for (int i = n - k; i < n; i++) {
            ans.push_back(nums[i]);
        }
        
        // 2. Get the remaining elements that move to the back
        for (int i = 0; i < n - k; i++) {
            ans.push_back(nums[i]);
        }
        
        // 3. Copy the result back into the original array
        nums = ans;
    }
};