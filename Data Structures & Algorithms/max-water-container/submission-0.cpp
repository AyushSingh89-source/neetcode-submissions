class Solution {
public:
    int maxArea(vector<int>& heights) {
        int min_hei = 0;
        int ans = 0;
        for(int i=0;i<heights.size()-1;i++){
            for(int j=i+1;j<heights.size();j++){
                min_hei = min(heights[i],heights[j]);
                ans = max(ans,min_hei*(j-i));
            }
        }
        return ans;
    }
};
