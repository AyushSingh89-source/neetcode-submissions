class Solution {
public:
    bool backTrack(vector<int>& nums, int side, int index, vector<int>& sides){
        if(index == nums.size()){
            return true;
        }

        for(int i = 0; i < sides.size(); i++){
            if(sides[i] + nums[index] <= side){
                sides[i] += nums[index];

                if(backTrack(nums, side, index + 1, sides)){
                    return true;
                }

                sides[i] -= nums[index];

                // skip duplicate empty buckets
                if(sides[i] == 0) break;
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }

        if(sum % k != 0){
            return false;
        }

        int side = sum / k;

        // if any single number is greater than target, impossible
        if(*max_element(nums.begin(), nums.end()) > side){
            return false;
        }

        vector<int> sides(k, 0);
        sort(nums.rbegin(), nums.rend());  // largest first = better pruning

        return backTrack(nums, side, 0, sides);
    }
};