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


// count ones in a sorted binary array
int countOnes(int *arr, int n) {
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == 0) {
			start = mid + 1;
		} else {
			if (mid == 0 || arr[mid - 1] == 1) {
				return (n - mid);
			} else {
				high = mid - 1;
			}
		}
	}
	return 0;
}