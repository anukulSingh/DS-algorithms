.// 0 - 1 knapsack

int solve(int W, int wt[], int val[], int n, int dp[n][W]) {
        if (n == 0 || W == 0) {
            return 0;
        }
        if (dp[n][W] != -1) return dp[n][W];
        
        if (wt[n-1] <= W) {
            return dp[n][W] = max(val[n-1] + solve(W - val[n-1], wt, val, n -1, dp), solve(W, wt, val, n- 1, dp));
        } else {
            return dp[n][W] = solve(W, wt, val, n- 1, dp);
        }
    }
int knapSack(int W, int wt[], int val[], int n) 
{ 
       // Your code here
       int dp[n+1][W+1];
       memset(dp, -1, sizeof(dp));
       return solve(W, wt, val, n, dp);
}

// subset sum problem
 bool solve(vector<int>arr, int n, int sum, vector<vector<int>> &dp) {
        if (sum == 0) return true; // returns true also when n = 0 and sum = 0
        if (n == 0) return false;
        
        if (dp[n][sum] != -1) return dp[n][sum];
        
        if (arr[n-1] <= sum) {
            return dp[n][sum] = solve(arr, n - 1, sum - arr[n-1], dp) || solve(arr, n-1, sum, dp);
        } else {
            return dp[n][sum] = solve(arr, n-1, sum, dp);
        }
    }
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    return solve(arr,n, sum, dp);
}


// equal sum partition
// check if it can be div into  2 substs such that bith has same sum
// take th sum, if odd, then not possible
// if even , then isSubset(arr, sum/ 2) wll give the result


// count of subset sum
// plus instead of OR
// if (n == 0) return 0
// if (sum == 0) return 1


// count thne no if subset with given diff
// i.e,
// sum(s1)  - sum(s2) = diff
// sum (s1) + sum(s2) = sum(arr)
// solving, sum(s1) = diff + sum(arr) / 2
// not it is the count of subset sum problem

// target sum 
// same as prev variation


// minimum subset sum diff (to study)



// total ways to get the coins
 int solve(int amount, vector<int>& coins, int n, vector<vector<int>> &dp) {
        if (n == 0) return 0;
        if (amount == 0) return 1;
        if (dp[n][amount] != -1) return dp[n][amount];
        
        if (coins[n-1] <= amount) {
            return dp[n][amount] = solve(amount - coins[n-1], coins, n, dp) + solve(amount, coins, n - 1, dp);
        } else {
            return dp[n][amount] = solve(amount, coins, n - 1, dp);
        }
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp (n + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins, n, dp);
    }