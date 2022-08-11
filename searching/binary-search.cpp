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