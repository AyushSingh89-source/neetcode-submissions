class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size(); 
        
        int start = 0;
        int last = m - 1; 

        while (start <= last) {
            if (matrix[start][n - 1] < target) {
                start++;
            } 
            else {
                int start1 = 0;
                int last1 = n - 1;

                while (start1 <= last1) {
                    int mid = start1 + (last1 - start1) / 2;
                    if (matrix[start][mid] == target) {
                        return true;
                    }
                    else if (matrix[start][mid] > target) {
                        last1 = mid - 1; 
                    }
                    else {
                        start1 = mid + 1; 
                    }
                }
                return false; 
            }
        }
        return false;
    }
};