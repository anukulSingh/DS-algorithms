int binarySearch(int * arr, int n , int x) {
	int start = 0, end = n-1;
	while(start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == x) return true;
		else if (arr[mid] > x) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
	return false;
}


// binary search on reverse sorted array
int descBinarySearch(int *arr, int n, int x) {
	int start = 0, end = n-1;
	while(start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == x) return true;
		else if (arr[mid] > x) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}

// order agnostic search
// not giving whether it is asc or desc sorted
// just compare the two elements start and end, and call functions according to it


int firstOcc (int *arr, int n, int x) {
	int start = 0, end = n-1;

	while(start <= end) {
		int mid = start + (end - start)/2;
		if (arr[mid] > x) {
			high = mid - 1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			if (arr[mid - 1] !== arr[mid] || arr[mid] == 0) {
				return mid;
			}
			else {
				high = mid - 1;
			}
		}
	}
	return -1;
}


int lastOcc (int *arr, int n, int x) {
	int start = 0, end = n-1;

	while(start <= end) {
		int mid = start + (end - start)/2;
		if (arr[mid] > x) {
			high = mid - 1;
		}
		else if (arr[mid] < x) {
			low = mid + 1;
		}
		else {
			if (arr[mid + 1] !== arr[mid] || arr[mid] == 0) {
				return mid;
			}
			else {
				low = mid + 1;
			}
		}
	}
	return -1;
}

// subtracting both of the above, we can get count of occurence of an element


// no of times a sorted array is rotated = index of minimum element, we can do this in O(n) (naive)
//  number of rotation in clockwise direction =len(array)-index of minimum element 
// now we find min element using b-search
// here reqd element is the only no smaller than bith of its neighbour

//For a sorted (in increasing order) and rotated array, the pivot element is the only element for which the next element to it is smaller than it.
int countRotatedFreq (int *arr, int n) {
	int start = 0, end = n-1;

	while (start <= end) {
		if (arr[start] <= arr[end]) {
			return start;
		}

		int mid = start + (end - start) / 2;
		int prev = ( mid + n - 1 ) % n; // to implement circularity
		int next = (mid + 1) % n;

		// check if mid is minimum
		if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
			return mid;
		}
		// find the sorted half, as min lies in unsorted half
		else if (arr[start] <= arr[mid]) { 
			start = mid + 1;
		}
		else if (arr[mid] <= arr[end]) { 
			end = mid - 1;
		}
	}
	return -1;
}


// search in a sorted rotated array
// variation of previous one
 int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int n = nums.size();
        while (start <= end) {
         
            int mid = start + (end - start) / 2;
          
            if (nums[mid] == target){
                return mid;
            }
            // we try to binary search in sorted half
            else if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                }
                else {
                  start = mid + 1;  
                }   
            }
            else {
                if (target >= nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;      
                }
            }
        }
        return -1;
  }

// search in nearly sorted array
  // compare for mid. mid+1, mid -1
  int searchAlmostSorted (int *arr, int n, int x) {
  	int start = 0, end = n-1;
  	while(start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
        	return mid;
        }
        else if (mid >= start && arr[mid - 1] == x) {
        	return mid -1;
        }
        else if (mid <= end && arr[mid + 1] == x) {
        	return mid+1;
        }
        else if (arr[mid] > x) {
        	end = mid - 2;
        }
        else {
        	start = mid + 2;
        }

  	}
  	return -1;
  }


// largest no lte to given no, upper_bound
  int findFloor (int *arr, int n, int x) {
  		int start = 0, end = n- 1;
  		int res = -1;
  		while(start <= end) {
  			int mid = start + (end - start) / 2;

  			if (arr[mid] == x) {
  				res = mid;
  				break;
  			}
  			else if (arr[mid] > x) {
  				end = mid - 1;
  			}
  			else {
  				res = mid;
  				start = mid + 1;
  			}
  		}
  		return res;
  }

  // smallest no gte to given no ,, lower_bound
  int findCeil (int *arr, int n, int x) {
  		int start = 0, end = n- 1;
  		int res = -1;
  		while(start <= end) {
  			int mid = start + (end - start) / 2;

  			if (arr[mid] == x) {
  				res = mid;
  				break;
  			}
  			else if (arr[mid] < x) {
  				start = mid + 1;
  			}
  			else {
  				res = mid;
  				end = mid - 1;
  			}
  		}
  		return res;
  }


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


    // allocate pages of book
    bool isValid (int *nums, int n, int k, int ans) {
    	int student = 1;
    	int sum = 0;

    	for (int i = 0 ; i < n; ++i) {
    		sum = sum + nums[i];
    		if (sum > ans) {
    			student++;
    			sum = nums[i];
    		}
    		else {
    			sum += nums[i];
    		}
    	}
        return (student <= k);
    }

    int allocateMinBooks (int *arr, int n, int k) {
    	int sum = 0, maxEl = 0;
    	int res = -1;

    	for (int i = 0; i < n; ++i) {
    		sum += arr[i];
    		maxEl = max(maxEl, arr[i]);
    	}
    	int start = maxEl, end = sum;

    	while (start <= end) {
    		int mid = start + (end - start) / 2;
    		if (isValid(arr, n, k, mid)) {
    			res = mid;
    			end = mid - 1;
    		}
    		else {
    			start = mid + 1;
    		}
    	}
    	return res;
    }