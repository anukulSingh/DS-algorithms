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
                  start = mid + 1;  // it does not lie in sorted half
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
