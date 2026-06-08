class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The minimum possible speed is 1 banana per hour
        int low = 1; 
        
        // The maximum useful speed is the size of the largest pile
        int high = 0;
        for (int pile : piles) {
            high = max(high, pile);
        }
        
        int result = high; // Store the best working speed found so far
        
        // Binary search for the sweet spot speed
        while (low <= high) {
            int mid = low + (high - low) / 2; // Current speed we are testing
            
            // Calculate total hours needed at speed 'mid'
            long long total_hours = 0;
            for (int pile : piles) {
                // This is a clean way to do ceiling division: ceil(pile / mid)
                total_hours += (pile + mid - 1) / mid;
            }
            
            // If Koko can finish within h hours, this speed works!
            if (total_hours <= h) {
                result = mid;      // Record this as a possible answer
                high = mid - 1;    // Try to find an even slower (better) speed
            } else {
                low = mid + 1;     // Too slow! We must try a faster speed
            }
        }
        
        return result;
    }
};