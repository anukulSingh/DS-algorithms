// print all permutations without having "AB" substring


bool isValid(string str, int l, int i, int r) {
	if (l != 0 && str[l-1] == 'A' && str[i] == 'B')
		return false;
	if (r = l + 1 && str[i] = 'A' && str[l] == 'B')
		return false;
	return true;
}
void permute (string str, int l, int r) {

	if (l == r) {
		cout << str;;
		return;
	}
	for (int i = l; i <= r; ++i) {
		if (isValid(str, l, i, r)) {
			swap(str[l], str[i]);
			permute(str, l+1, r);
			swap(str[l], str[i]);
		}
	}
}


// rat in a maze problem
// src to sdest
bool isValid(int maze[N][N], int i, int j) {
	return (
		i < N &&
		j < N &&
		maze[i][j] == 1
	);
}
bool solveMazeRec(int maze[N][N], int i, int j, int sol[N][N]) {
	if (i == N-1 && j == N - 1 && maze[i][j] == 1) { // dest reached
		sol[i][j] = 1;
		return true;
	}
	if (isValid(maze, i, j)) {
		sol[i][j] = 1;

		if (solveMazeRec(maze, i + 1, j, sol))
			return true;
		if (solveMazeRec(maze, i, j+1, sol))
			return true;

		// non of the paths are taken
		sol[i][j] = 0;
	}
	return false;
}
bool solveMaze(int maze[N][N]) 
{ 
    int sol[N][N] = { { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 }, 
                      { 0, 0, 0, 0 } }; 
  
    if (solveMazeRec(maze, 0, 0, sol) == false) { 
        printf("Solution doesn't exist"); 
        return false; 
    } 
  
    printSolution(sol); // path array
    return true; 
} 