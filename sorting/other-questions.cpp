// merge overlapping intervals
// given an array of pairs
// eff - sort all by increasing order by start time
void mergeOverlapping (int *arr, int n) {
	sort(arr, arr+n, cmp);
	int prev = 0;
	for (int i = 1; i < n; ++i) {
		if (arr[prev].end >= arr[i].start) {
			arr[prev].end = max(arr[prev].end, arr[i].end);
			arr[prev].start = min(arr[prev].start, arr[i].end)
		} else {
			prev++;
			arr[prev] = arr[i];
		}
	}
	for (int x : arr)
		cout << x.start << " " < x.end;
}


// meeting maximum guests
// given arrival and departure time of all guests, go at a time when you can meet max no of people, find that max guests
int maxMeetings (int *arr, int *dep, int n) {
	sort (arr, arr+n) // sort arrivals
	sort (dep, dep+n) // sort departures

	int i = 1, j = 0, res = 1, curr = 1;
	while (i < n && j < n) {
		// check if the next event is arrival or departure
		if (arr[i] <= dep[j]) {
			curr++;
			i++;
		} else {
			curr--;
			j++;
		}
		res = max(res, curr);
	}
	return res;
}


// median of two sorted arrays

double getMedian(int *a1, int *a2, int n1, int n2) {
	int start1 = 0, end = n1; // we will do b search in first smaller sized array
	while (start1 <= end1) {
		int i1 = start1 + (end1 - start1) / 2;
		int i2 = (n1 + n2 + 1) - i1; // corrspinsifng mid in second array

		int min1 = (i1 == n1) ? INT_MAX : a1[i1]; // min element of right half of first array
		int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1]; // max element of left half of left half of first array

		int min2 = (i2 == n2) ? INT_MAX : a2[i2]; // min element of right half of second array
		int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1]; // max element of left half of left half of second array

		if (max1 <= min2 && max2 <= min1) { // condition achieved, half elements in left, and half in right
			if ((n1 + n2) % 2 == 0) {
				return ((double) max(max1, max2) + min(min1, min2) / 2);
			} else {
				return (double) max(max1, max2);
			}
		} else if (max1 > min2) { // more elements of second array can be taken in left
			end1 = i1 - 1
		} else {    // some elements of second array are wrongly in right
			start1 = i1 + 1;
		}
	}
}