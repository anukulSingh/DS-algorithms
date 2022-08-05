#include <iostream>
using namespace std;

// maximum subarray sum
// Kadane's approach
// maxEnding[i] = max(maxEnding[i-1] + arr[i], arr[i]);
// we can also build an array where dp[i] = dp[i-1] + arr[i]; 
int normalMaxSum(int *arr, int n) {
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i=1; i<n; ++i) {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res, maxEnding);
    }
    return res;
}

// length of longest even odd(alternating) subarray length
int evenOdd(int *arr, int n) {
    int res = 1, curr =1;
    for (int i = 1; i<n; ++i) {
        if ((arr[i] %2 == 0 && arr[i-1] % 2 != 0) || (arr[i] %2 != 0 && arr[i-1] % 2 == 0)) {
            curr++;
            res = max(res,curr);
        }
        else {
            curr = 1;
        }
    }
    return res;
}
// maxCircular = arr_sum - normalMinSum
// normalMinSum = -(normalMaxSum in an inveted array)
int overallMaxSum(int *arr, int n) {
    int max_normal = normalMaxSum(arr, n);
    if (max_normal < 0) return max_normal;

    int arr_sum = 0;
    for(int i = 0; i < n; ++i) {
        arr_sum += arr[i];
        arr[i] = -arr[i];
    }
    int max_circular = arr_sum + normalMaxSum(arr, n);

    return max(max_normal, max_circular);
}

// majority element
// Moore's voting algorithm
// whether an element appears more than once
// int findMajority(int *arr, int n) {
//     // find a candidate
//     int res =0, count = 1;
//     for(int i = 1; i<n; ++i) {
//         if (arr[res] == arr[i])
//             count++;
//         else
//             count--;

//         if (count == 0) {
//             res = i;
//             count = 1;
//         }
//     }
// }

// window sliding technique
// find max sum of k consecutive elements
// we take one window and compare it with other windows
int maxSUmK(int *arr, int n, int k) {
    int curr_sum = 0;
    for(int i = 0; i < k; ++i)
        curr_sum += arr[i];
    
    int max_sum = curr_sum;
    for(int i = k; i < n; ++i) {
        curr_sum += (arr[i] - arr[i-k]);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

// given an unsorted array with non negative eles, find if there subarray with given sum, TC & AS o(n) 
// if there are both positive and neg eles, we use hashing, with O(n) extra space
// here add elements to window until same is smaller, if sum exceeds, remove from start
bool checkSum(int *arr, int n, int sum) {
    int curr_sum = arr[0], s= 0;
    for (int e = 1; e < n; e++) {
        //clear the prev window
        while (curr_sum > sum && s < e-1) {
            curr_sum -= arr[s++];
        }
        if (curr_sum == sum)
            return true;
        if (e < n)
            curr_sum += arr[e];
    }
    return (curr_sum == sum);
}

// N-bonacci 
void nbonacci (int n, int m) {
    long long arr[m] = {0};
    arr[n-1] = 1;
    arr[n] = 1;
    for(int i = n+1; i < m; ++i) {
        arr[i] = 2 * arr[i-1] - arr[i-n-1];
    }
    for(long long x: arr)
        cout << x<< " ";
}


int main() {

    // int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    // int arr[] = {10,12,14,7,8};
    // int arr[] = {8,-4,3,-5,4};
    int arr[] = {1, 8,30,-5, 20, 7};


    // cout << normalMaxSum(arr,7);
    // cout << overallMaxSum(arr, 5);
    // cout << evenOdd(arr,5);
    // cout << maxSUmK(arr, 6, 3);
    // checkSum(arr, 6, 46) ? cout <<"yes" : cout<< "no";

    nbonacci(3, 80);
    return 0;
}
