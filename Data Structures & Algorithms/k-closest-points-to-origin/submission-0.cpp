class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                int d1 = points[j][0]*points[j][0] + points[j][1]*points[j][1];
                int d2 = points[j+1][0]*points[j+1][0] + points[j+1][1]*points[j+1][1];

                if(d1>d2){
                    vector<int> temp = points[j];
                    points[j] = points[j+1];
                    points[j+1] = temp;
                }
            }
        }

        vector<vector<int>> result;

        for(int i=0;i<k; i++){
            result.push_back(points[i]);
        }

        return result;
    }
};
