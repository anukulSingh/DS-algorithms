// this takes quadratic TC in average
// better soln with  heap in nlogk
// median order statistics in linear time
int kthsmallest(int *arr, int n, int k) {
	int l =0, r = n -1;
	while (l <= r) {
		int pivot = lpartition(arr l, r);
		if (pivot == k-1) return p;
		else if (pivot > k-1) r = pivot -1;
		else l = pivot + 1;
	}
	return -1;
}


/* segragate two types of groups
even-odd / +ve -ve / binary array */
void sortBinary(int *arr, int n) {
	int i = -1, j = n;
	while (true) {
		do {
			i++;
		} while(arr[i] < 0);
		do {
			j--;
		} while(arr[j] >= 0);

		if (i >= j)
			return;
		swap(arr[i], arr[j]);
	}
}

/* sort an array of 3 types of elements */
/* 3 types of problems
	1. sort an array of 0s is and 2s
	2. three way partitioning when multiple occurences of pivot may exist
	3. partitioning around a range

we can use dutch national flag algorithm to solve it
keep track of 3 variables
0 - low - 1 has 0s
low - mid - 1 has 1s
mid - high - unknowns
high - n-1 - 2s
*/


void sortDutch(int *arr, int n) {
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		switch(arr[mid]) {
			case 0:
				swap(arr[low], arr[mid]);
				low++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(arr[mid], arr[high]);
				high--;
				break;
		}
	}
}