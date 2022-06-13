#include <iostream>
using namespace std;

// keep track of index of largest and second largest element in array, take a llok
// int secondLargest(int *arr, int n) {
//     int res = -1, largest = 0;
//     for (int i = 1; i < n; ++i) {
//         if (arr[i] > arr[largest]) {
//             res = largest;
//             largest = i;
//         }
//         else if (arr[i] != arr[largest]){
//             if ((res == -1) || (arr[i] > arr[res]))
//                 res = i;
//         }
//     }
//     return res;
// }

// check if array is sorted
// one  way of keeping track of two els

// bool isSorted (int *arr, int n) {
//     for (int i = 1; i < n; ++i) 
//         if (arr[i] < arr[i-1])
//             return false;
//     return true;
// }

// Reverse an array
void reverse (int *arr, int d, int n) {
    int low = d, high = n;
    while (low < high) {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
    // for (int i = 0; i<n; ++i)
    //     cout << arr[i]<< " ";
}

// Remove dups from sorted array and return size of first distinct
// another way of keeping track of two elements
// void removeDuplicate (int *arr, int n) {
//     int res = 1;
//     for (int i =1; i <n; ++i) {
//         if (arr[i] != arr[res-1]) {
//             arr[res] = arr[i];
//             res++;
//         }
//     }
//     for (int i = 0; i<n; ++i)
//          cout << arr[i]<< " ";
//     cout<<endl;
//     return res;
// }

// move all zeroes to end, maintaining the order
// void moveToEnd(int *arr, int n) {
//     int count = 0;
//     for (int i =0; i < n; ++i) {
//         if (arr[i] != 0) {
//             swap(arr[i], arr[count]);
//             count ++;
//         }
//     }
// }

// left rotate arry by D places
// void leftRotate(int *arr, int n, int d) {
//     reverse(arr, 0, d-1);
//     reverse(arr,d,n-1);
//     reverse(arr, 0, n-1);
// }

// // right rotate array by d places
// void rightRotate(int *arr, int n, int d) {
//     reverse(arr, 0, n-1);
//     reverse(arr, 0, d-1);
//     reverse(arr, d, n-1);
// }

// Leaders in an array, take a look
// void leaders(int *arr, int n) {
//     int curr_index = arr[n-1];
//     cout << curr_index<<" ";
//     for(int i = n-2; i >= 0; --i) {
//         if (curr_index < arr[i]) {
//             curr_index = arr[i];
//             cout << curr_index<<" ";
//         }
//     }
// }

// Maximum difference algorithm (order matters)
// another way of keeping tracks in array
// int maxDifference(int *arr, int n) {
//     int res = arr[1] - arr[0];
//     int minVal = arr[0];

//     for(int i =0; i < n; ++i) {
//         res = max(res, arr[i] - minVal);
//         minVal = min(minVal, arr[i]);
//     }
//     return res;
// }

// frequency in sorted array
// void printFreq(int *arr, int n) {
//     int freq = 1, i =1;
//     while (i < n) {
//         while(i < n && arr[i] == arr[i-1]){
//             freq++;
//             i++;
//         }
//         cout << arr[i-1] << ": "<< freq<<"\n";
//         i++;
//         freq =1;
//     }
//     if(n == 1 || arr[n-1] != arr[n-2])
//          cout << arr[n-1] << ": "<< 1<<"\n";
// }

// max profit for stock,buy and sell problem
// int maxProfit(int *price, int n) {
//     int profit = 0;
//     for(int i = 1; i < n; ++i) {
//         if (price[i] > price[i-1])
//             profit += (price[i] - price[i-1]);
//     }
//     return profit;
// }

// max consec digit in an array, here binary array
// int maxConsecutive(int *arr, int n) {
//     int curr;
//     int res = 0;
//     for(int i = 0; i < n; ++i) {
//         if(arr[i] == 0)
//             curr = 0;
//         else {
//             curr ++;
//             res = max(res, curr);
//         }
//     }
//     return res;
// }

// Trapping Rainwater problem
// int getWater(int *water, int n) {
//     int res = 0;
//     int lmax[n],rmax[n];

//     lmax[0] = water[0];
//     for(int i =1; i < n; ++i)
//         lmax[i] = max(water[i], lmax[i-1]);
    
//     rmax[n-1] = water[n-1];
//     for(int i = n-2; i >= 0; --i) 
//         rmax[i] = max(water[i], rmax[i+1]);

//     for(int i = 1; i < n-1; ++i)
//         res += (min(lmax[i], rmax[i]) - water[i]);

//     return res;
// }


// Prefix sum technique
// given l and r, we have many queries to getSum till
// getSUm(0,3), getSum(2,3) etc
// void buildPrefixSum (int *arr, int n) {
//     int prefix_sum[n];
//     prefix_sum[0] = arr[0];
//     for (int i = 1; i < n; ++i) {
//         prefix_sum[i] = prefix_sum[i-1] + arr[i];
//     }
// }
//now to get a sum.
// we can find any sum in a range, given l and r
int getSum (int *prefix_sum, int l, int r) {
    if (l != 0)
        return (prefix_sum[r] - prefix_sum[l-1]);
    return prefix_sum[r];
}

// find eqb point in an array
// if sum before that element is equal to that of after the element
// using prefix sum technique
bool isEqb (int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum+= arr[i];
    int l_sum = 0;
    for (int i = 0; i < n; ++i) {
        if (l_sum == (sum - arr[i]))  // checking eqb for every point
            return true;
        l_sum += arr[i];
        sum -= arr[i];
    }
    return false;
}

// given n ranges, find maximum appearing element in their ranges
// ex l[] = {1,2,5,15}, r[] = {5,8,7,18}, l[i] < r[i]
// then ranges are 1-5, 2-8, 5-7, 15-18
// here 5 is most frequent among all these ranges
// and given 0 < l[i], r[i] < 1000

int maxOcc (int *l , int *r, int n) {
    int arr[1000] = {0};
    for (int i = 0; i < n; ++i) {
        arr[l[i]]++;
        arr[r[i] + 1]--;
    }
    // array formed is {0, 1, 2, 3, 2, 2, 1, 0,... }
    // 0 occurs arr[0] times i.e. 0 times
    // 1 occurs arr[1] times i.e. 1 time..
    // 3 occurs arr[3] times i.e. 3 times
    int maxm = arr[0], res = 0;
    // while doing prefix sum, check if current_sum > max_sum
    for (int i = 1; i < 1000; ++i) {
        arr[i] += arr[i-1];
        if (maxm < arr[i]) {
            maxm = arr[i];
            res = i;
        }
        return res;
    }
}


int main() {

    // int arr[] = {12,14,17,10};
    // int arr[] = {10,10,20,30,40,40,40,50};
    // int arr[] = {10, 20,30, 10,20,30,10,40};
    // int arr[] = {10,0,9,0,3,4,0};
    // int price[] = {1,5,3,8,12};
    // int water[] = {3,0,1,2,5};
    // int arr[] = {1,0,0,1,1,1,1,0,0,0,0,1};

    // int n; cin >> n;
    // cout << n;

    // cout << secondLargest(arr, 4);
    // isSorted(arr, 4) ? cout << "Sorted.." : cout << "Unsorted..";
    // reverse(arr, 4);
    // cout << removeDuplicate(arr, 8);
    // moveToEnd(arr,8);

    // leftRotate(arr, 7, 3);
    // rightRotate(arr,7,3);

    // cout << maxDifference(arr, 4);
    // leaders(arr, 4);

    // printFreq(arr,8);
    // cout << maxProfit(price,5);

    // cout << getWater(water, 5);
    // cout << maxConsecutive(arr, 12);

    // for(int x: arr)
    //     cout << x << " ";

    int l[] = {1, 2, 3};
    int r[] = {3, 5, 7};
    return 0;
}