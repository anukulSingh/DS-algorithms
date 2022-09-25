// edit distnace problem
// convert string s1 to s2, minimum no fo ops
// you can delete a char, inser a char, replace a char with any other char
// recursive
int ed (string s1, string s2, int m, int n) {
	if (m == 0) return n; // if first string is 0, we gotta insert n
	if (n == 0) return m; // if second string 0, we gotta delete first string

	if (s1[m-1] == s2[n-1])
		return ed(s1, s2, m-1, n-1); // ignore lastof both

	// return 1 + min(
	// 	ed(s1, s2, m, n-1), // insert last character of second string to first
	// 	ed (s1, s2, m-1, n), // delete a char from first string
	// 	ed (s1, s2, m-1, n-1) // replace last character
	// )

	// we can compare three mins as follows
	return 1 + min(
		ed(s1, s2, m, n-1),
		min(
			ed(s1, s2, m-1, n),
			ed(S1, s2, m-1, n-1)
		)
	);
}

// dp approach
int ed (string s1, string s2, int m, int n) {
	int dp[m+1][n+1];

	for (int i = 0; i <= m; ++i) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= n; ++j) {
		dp[0][j] = j;
	}

	for (int i = 1; i<= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1];
			} else {
				dp[i][j] = min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))
			}
		}
	}
	return dp[m][n];
}


// LIS
// find length of longest subsequence such that all elements of subsequence are in sorted order
// approach - find lis ending with all the array elements, max of them goves the ans
// to construct lis array, we need to left to that element, and check for the max previous LIS

int LIS(int *arr, int n) {
	int lis[n];

	for (int i = 0; i < n; ++i) {
		lis[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i]) {
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}
	return *max_element(lis, lis + n);
}