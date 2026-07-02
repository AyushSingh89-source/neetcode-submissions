class Solution {
public:
    int island = 0;

    void dfs(vector<vector<char>>& grid, int row, int col, vector<vector<bool>>& visited) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        // out of bounds or water or already visited -> stop
        if (row < 0 || row >= totalRows || col < 0 || col >= totalCols) {
            return;
        }
        if (grid[row][col] == '0' || visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        dfs(grid, row + 1, col, visited);
        dfs(grid, row - 1, col, visited);
        dfs(grid, row, col + 1, visited);
        dfs(grid, row, col - 1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    island++;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return island;
    }
};