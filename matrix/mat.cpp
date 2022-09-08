#include <iostream>
#define FOR(a, b) for (int a = 0; a < b; ++a)
using namespace std;

const int R = 3;
const int C = 5;

// print matrix in snake order
void printSnake (int mat[R][C]) {
    FOR (i, R) {
        if (i & 1) {
            for (int j = C-1; j >= 0; --j)
                cout << mat[i][j]<< " ";
        } else {
            FOR (j,C) 
                cout << mat[i][j]<< " ";
        }
    }
}

// Matrix boundary traversal
void printBoundary (int mat [R][C]) {

//side cases
    if (R == 1) 
        FOR (i,C)
            cout << mat[0][i] << " ";
    else if (C == 1)
        FOR (i,R)
            cout << mat[i][0] << " ";
//side cases
    else {
        FOR (i,C)
            cout << mat[0][i] << " ";

        for (int i = 1; i < R; ++i)
            cout << mat[i][C-1] << " ";

        for (int i = C-2; i >= 0; --i)
            cout << mat[R-1][i] << " ";
        
        for (int i = R-2; i >= 1; --i)
            cout << mat[i][0] << " ";
        
    }
}


// transpose of a matrix
// Efficient - swap upper diag ele with lower diag ones
void transpose (int mat[R][C]) {
    FOR (i, R)
        for (int j = i + 1; j < C; ++j)
            swap(mat[i][j], mat[j][i]);
}


// In-place counter clockwise rotation by 90 deg
void counterRotate (int mat[R][C]) {

    transpose(mat);
    FOR (j,C) {
        int low = 0, high = R -1;
        while (low < high) {
            swap (mat[low][j], mat[high][j]);
            low++; high --;
        }
    }

}

// Spiral traversal of a matrix
void printSpiral (int mat[R][C]) {

    int top = 0, left = 0, right = C-1, bottom = R - 1;
    while (top <= bottom && left <= right) {

        // Top row
        for (int i = left; i <= right; ++i)
            cout << mat[top][i] << " ";
        top++;
        // Right column
        for (int i = top; i <= bottom; ++i)
            cout << mat[i][right] << " ";
        right--;
        // Bottom row
        for (int i = right; i >= left; --i) 
            cout << mat[bottom][i] << " ";
        bottom--;
        // Left column
        for (int i = bottom; i >= top; --i) 
            cout << mat[i][left] << " ";
        left++;
    }

}


// search in a row-wise column-wise sorted matrix
// Start from top right
// if x is smaller move left, if greater move down
void search (int mat[R][C], int x) {

    int i = 0, j = C-1;
    while (i < R && j >= 0) {
        if (mat[i][j] == x) {
            cout << "Found at (" << i << ", " << j << ")";
            return; 
        }
        else if (mat[i][j] > x) j--;
        else i++;
    }
    cout << "Not found";
}
// median of a row wise sirted matrix
// TC O(R*log(max - min) * log C) ~= O(R0 ), good for large sized matrix
int medianRowSorted (int mat[R][C]) {
    // first find min and max element
    int min = mat[0][0], max = mat[0][C-1];
    for (int i = 1; i < R; ++i) {
        if (mat[i][0] < min) {
            min = mat[i][0];
        }
        if (mat[i][C-1] > max) {
            max = mat[i][C-1];
        }
        // median position
        int medPos = (R*C + 1)/2;
    }
}
int main() {

    // int arr[R][C] = {
    //                {1, 2, 3, 4},
	// 			   {5, 6, 7, 8},
	// 			   {9, 10, 11, 12},
	// 			   {13, 14, 15, 16}
    //                };

    // printSnake(arr);
    // printBoundary(arr);

    // transpose(arr);
    // FOR (i, R) {
    //     FOR(j, C)
    //         cout << arr[i][j] << " ";
    //     cout << "\n";
    // }

    // counterRotate(arr);
    //     FOR (i, R) {
    //     FOR(j, C)
    //         cout << arr[i][j] << " ";
    //     cout << "\n";
    // }

    // printSpiral(arr);
    // search(arr, 10); 

    int arr[R][C] = {
        {5, 10, 20, 30, 40},
        {1, 2, 3, 4, 6},
        {11, 13, 15, 17, 19}
    }


    return 0;
}