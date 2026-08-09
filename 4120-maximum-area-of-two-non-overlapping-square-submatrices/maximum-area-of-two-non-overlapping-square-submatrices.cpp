class Solution {
public:

    bool canPlace(vector<vector<int>>& dp, int k) {
        int m = dp.size();
        int n = dp[0].size();
        int minTop = m;
        int minLeft = n;
        int maxLeft = -1;
        for (int r = k - 1; r < m; r++) {
            for (int c = k - 1; c < n; c++) {
                if (dp[r][c] >= k) {
                    int topRow = r - k + 1;
                    int leftCol = c - k + 1;
                    if (topRow - minTop >= k)
                        return true;
                    if (leftCol - minLeft >= k)
                        return true;
                    if (maxLeft - leftCol >= k)
                        return true;
                    minTop = min(minTop, topRow);
                    minLeft = min(minLeft, leftCol);
                    maxLeft = max(maxLeft, leftCol);
                }
            }
        }

        return false;
    }


    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0)
                    continue;

                dp[i][j] = 1;

                if (i > 0 && j > 0) {
                    dp[i][j] += min({
                        dp[i - 1][j],
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    });
                }
            }
        }
        int low = 1;
        int high = min(m, n);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canPlace(dp, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans * ans;
    }
};