







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





/* get floor of nth root */
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int low = 1, high = m;
	    int ans = -1;
	    while (low <= high) {
	        int mid = low + (high - low) /2 ;
	        double nsq = pow(mid, n);
	        if (nsq == m) {
	            return mid;
	        } else if (nsq > m) {
	            high = mid-1;
	        } else {
	            low = mid + 1;
	        }
	    }
	    return ans;
}  


