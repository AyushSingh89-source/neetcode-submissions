class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left =0;
        int right = 0;

        for(int i=0;i<weights.size();i++){
            left = max(left,weights[i]);
            right += weights[i];
        }

        while(left< right){
            int mid = left + (right-left)/2;
            int daysNeeded = 1;
            int currentLoad = 0;

            for(int i=0;i<weights.size(); i++){
                if(currentLoad + weights[i] > mid){
                    daysNeeded ++;
                    currentLoad = 0;
                }
                currentLoad += weights[i];
            }
            if(daysNeeded>days){
                left  = mid +1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};