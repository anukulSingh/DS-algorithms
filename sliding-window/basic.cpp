// chocolate distb problem
// sorted windows
// here finding min diff of two elements across all the windows
 long long findMinDiff(vector<long long> a, long long n, long long m){
        //code
        sort(a.begin(), a.end());
        int min_diff = INT_MAX;
    
    // sliding window fixed size
    // n is size of arr, m is window size
        for (int i = 0; i + m -1 < n; ++i) {
            int diff = a[i + m - 1] - a[i];
            min_diff = min(min_diff, diff);
        }
        return min_diff;
   }


   // first negative number in evry wino of sixe k
   int firstNegatve (int *arr, int n, int k) {
    queue<int> q;
    vector<int> ans;
        int i = 0, j = 0;
        while (j < n) {
            // add to the queue if negative
            if (arr[i] < 0) {
                q.push(arr[i]);
            }
            if (j + i - 1 < k) {
                ++j;
            } else if (j +i - 1 == k) {
                // if no negative element in current window
                if (q.size() == 0) ans.push_back(0);
                else {
                    // take the first negative
                    ans.push_back(q.front());

                    // if the element to be removed from the window (first element in window) is actually the first negative no we found
                    // we have to remove it from queue
                    // if not then it will be in oter window 
                    if (arr[i] == q.front()) q.pop();
                    
                    ++i;++j; // slide the window
                }
            }
        }
   } 