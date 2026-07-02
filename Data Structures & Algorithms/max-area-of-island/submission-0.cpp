class Solution {
public:
    int area = 0;

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }
        if(visited[row][col] || grid[row][col] == 0){
            return;
        }

        visited[row][col] = true;
        area += 1;

        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row - 1, col);
        dfs(grid, visited, row, col + 1);
        dfs(grid, visited, row, col - 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int ans = 0;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    area = 0;
                    dfs(grid, visited, i, j);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};