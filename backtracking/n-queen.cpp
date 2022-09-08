// n queen problem
// in a n * n chessboard, place n queens, so that no two can attack eachbother

bool board[n][n];
vector<vector<int>> result;
bool isSafe(int row, int col) {
	// check if any queen is already in the row
	for (int i = 0; i < col; ++i) {
		if (board[row][i])
			return false;
	}

	// check for upper diagonal
	for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
		if (board[i][j]) return false;
	}

	// check for lower diag
	for (int i = row, j = col; j >= 0 && i < n; ++i, --j) {
		if (board[i][j]) return false;
	}

	return true;

}
bool solveRec (int col) {
	if (col == n) { // // if reachd last column there si sol
		
		// printing logic
		vector<int> v;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 1) {
					v.push_back(j + 1);
				}
			}
		}
		result.push_back(v);
		// print logic

		return true;
	} 
	for (int i = 0; i < n; ++i) { // for each row
		if (isSafe(i, col)) {
			board[i][col] = 1;
			if (solveRec(col + 1))
				return true;

			board[i][col] = 0; // remove queen if false
		}
	}
	return false;
}
bool solve() {
	if (solveRec(0) == false) return false;
	else {
		return true;
	}
}

