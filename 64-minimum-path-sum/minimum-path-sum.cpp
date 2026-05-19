class Solution {
public:

    int m, n;

    int solve(int i, int j,
              vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        if (i >= m || j >= n) {
            return 1e9;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solve(i, j + 1, grid, dp);
        int down  = solve(i +1, j, grid, dp);

        return dp[i][j] =
               grid[i][j] + min(right, down);
    }

    int minPathSum(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return solve(0, 0, grid, dp);
    }
};