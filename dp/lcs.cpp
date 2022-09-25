// lCS

int solve(string text1, string text2, int m, int n, vector<vector<int>> &dp) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        if (text1[m-1] == text2[n-1]) {
            return dp[m][n] = 1 + solve(text1, text2, m-1, n-1, dp);
        } else {
            return dp[m][n] = max(solve(text1, text2, m-1, n, dp), solve(text1, text2, m, n-1, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(text1, text2, m, n, dp);
    }


// longest common substring
  int solve(string text1, string text2, int m, int n, vector<vector<int>> &dp, int &ans) {
        if (m == 0 || n == 0) return 0;
        if (dp[m][n] != -1) return dp[m][n];
        if (text1[m-1] == text2[n-1]) {
            dp[m][n] = 1 + solve(text1, text2, m-1, n-1, dp, ans);
            ans = max(ans, dp[m][n]);
            return dp[m][n];
        } else {
            return dp[m][n] = 0;
        }
    }
    int longestCommonSubstr (string S1, string S2, int m, int n)
    {
        // your code here
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = INT_MIN;
        int flag = solve(S1, S2, m, n, dp, ans);
        return ans;
    }



/* shortest common supersequence of a and b
 just do
 o/p = len(a) + len(b) - lcs(a, b)
 
*/

/*
Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2
# of deletions = str1 - lcs(str1, str2)
# of insertions = str2 - lcs(a, b);
*/

/*
    Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
    In one step, you can delete exactly one character in either string.
    o/p = len(a) + len(b) - 2*lcs(a, b)
 */

/*
    lps(a, b) = lcs(a, rev(a))
*/

/*
    min no of insertion in a str to make it a palindrome
    = min no of deletion in a str to make it a palindrome
    = str.length() - lps(a)
*/