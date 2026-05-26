class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int first = 0;
        int ans = INT_MAX;
        int sum = 0;

        for (int second = 0; second < nums.size(); second++) {
            sum += nums[second];

            while (sum >= target) {
                ans = min(ans, second - first + 1);
                sum -= nums[first];
                first++; 
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};