bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n, vector<bool>(k + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j == 0) {
                // If the sum required is 0, it is always possible to achieve
                dp[i][j] = true;
            } else if (i == 0) {
                // Check if the first element itself is equal to the sum required
                dp[i][j] = (arr[i] == j);
            } else {
                // Two possibilities: take the current element or not take it
                bool take = (j >= arr[i]) ? dp[i - 1][j - arr[i]] : false;
                bool not_take = dp[i - 1][j];
                dp[i][j] = take || not_take;
            }
        }
    }

    return dp[n - 1][k];
}