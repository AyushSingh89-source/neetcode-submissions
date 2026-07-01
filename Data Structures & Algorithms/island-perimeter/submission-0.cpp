class Solution {
public:
    int perimeter = 0;
    vector<vector<bool>> visited;

    void dfs(vector<vector<int>>& grid, int i, int j){
        // out of bounds OR water -> this side adds to the perimeter
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
            perimeter++;
            return;
        }
        // already-visited land -> stop here, don't recount or loop back
        if(visited[i][j]){
            return;
        }

        visited[i][j] = true;

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        // find any land cell to start the DFS from
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }
        return perimeter;
    }
};