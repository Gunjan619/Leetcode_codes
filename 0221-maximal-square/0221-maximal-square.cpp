class Solution {
public:
    int solve(vector<vector<char>>& matrix, int i, int j, vector<vector<int>>& dp) {
        if (i >= matrix.size() || j >= matrix[0].size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(matrix, i, j + 1, dp);
        int diagonal = solve(matrix, i + 1, j + 1, dp);
        int down = solve(matrix, i + 1, j, dp);

        int side = 0;
        if (matrix[i][j] == '1') {
            side = 1 + min(right, min(down, diagonal));
        }

        dp[i][j] = side; // memoization
        return side;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // memoization table
        
        int maxSize = 0;
        solve(matrix, 0, 0, dp); // fill the memoization table
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxSize = max(maxSize, dp[i][j]); // update maxSize
            }
        }

        return maxSize * maxSize; // return the area of the square
    }
};