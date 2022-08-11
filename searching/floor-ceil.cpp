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
