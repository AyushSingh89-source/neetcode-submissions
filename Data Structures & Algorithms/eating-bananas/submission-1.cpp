class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1; 
        
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        
        int result = high; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long long total_hours = 0;
            for (int pile : piles) {
                total_hours += (pile + mid - 1) / mid;
            }
            
            if (total_hours <= h) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};