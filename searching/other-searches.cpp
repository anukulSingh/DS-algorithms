 // find next letter of a key letter in sorted alphabetical array
  int nextLetter (char *arr, int n, char ele) {
  	int start = 0, end = n - 1;
  	int res = -1;

  	if (ele == char[n-1]) {
  		return -1;
  	}
  	while (start <= end) {
  		int mid = start + (end - start) / 2;
  		if (arr[mid] <= ele) {
  			start = mid + 1;
  		}
  		else if (arr[mid] > ele) {
  			res = mid;
  			end = mid - 1;
  		}
  	}
  	return res;
  }


  //position of an element in an inf sorted array
  int seacrchInf (int *arr) {
  	int start = 0, end = 1;
  	while (start <= end) {
  		if (arr[end] < key) {
  			start = end;
  			end *= 2;
  		}
  	}
  	if (arr[end] == key)
  		return end;

  	else if (arr[end] > key) {
  		int mid = start + (end - start) / 2;
  		if (arr[mid] == key) return mid;
  		else if (arr[mid] > key) {
  			end = mid - 1;
  		}
  		else {
  			start = mid + 1;
  		}
  	}
  	return -1;
  }


// combo of prev 2
  // index of first 1 in binary sorted inf array
  int firstOne (int *arr, int n) {

  }


  // given a ket=y, we have to find the element i in arr, st | arr[i] - key | is minimum
  // we can find the floor and ceil of the key, and compare among them for the minimum, simple


  // binary search on answer


  // peak element
  // giben an unsorted array
  // peak elment should be greater than both of its neighbour

  int peakIndex (int *arr, int n) {
  	int start =0, end - n -1;

  	int mid = start + (end - start) / 2;

  	while (start <= end) {
  		if (mid > 0 && mid < n-1) {
  			if (arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
  				return mid;
  			}
  			else if (arr[mid-1] > arr[mid]) {
  				high = mid - 1;
  			}
  			else {
  				low = mid + 1;
  			}
  		}
  		// edge cases
  		else if (mid == 0) {
  			if (arr[0] > arr[1])
  				return 0;
  			else
  				return 1;
  		}
  		else if (mid == n-1) {
  			if (arr[n-1] > arr[n-2])
  				return n-1;
  			else
  				return n-2;
  		}
  	}
  }


  // max element in bitonic array = the only peak element in bitoni array
// MI till on element , and then MD
// there is a single peak element i bitonic array



  // search in bitonic array
  // asending bs in start = 0, end = peak - 1
  // descending bs in start = peak, end = arr.size() -1


  // search in row wise and column wise sorted matrix
  // we can either go downward or leftward from top right corner
  // thus worse case O (n + m)

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() -1;
        
        while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                --j; // go left, change column
            else
                ++i; // go down, change row
        }
        return false;
    }



    // search in a matrix, where entries are sorted
    // first element if row is greater than last element of prev row
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size()) return false;
        int l0 = 0;
        int h1 = (matrix.size() * matrix[0].size()) - 1;
        
        while(l0 <= h1) {
            int mid = l0 + (h1- l0) / 2;
            if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) {
                return true;
            }
            else if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target) {
                l0 = mid + 1;
            }
            else
                h1 = mid - 1;
        }
        return false;
    }



 /* nth root of an integer
	TC is n*log2(m * pow(10, d))
 */
 double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}

void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; // for correct upto 6 decimal places
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}
