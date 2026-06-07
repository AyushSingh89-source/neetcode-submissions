class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int last = x ;

        while(start <= last){
            int mid = start + (last-start)/2;
            long long sqr = (long long)mid*mid;

            if(sqr == x){
                return mid;
            }
            else if(sqr < x){
                start = mid+1;
            }
            else{
                last = mid -1;
            }
        }
        return last;
    }
};