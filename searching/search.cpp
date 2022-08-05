#include <iostream>

using namespace std;

// int binarySearch(int *arr, int n, int x) {
//     int low = 0, high = n-1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] == x) return mid;
//         else if (arr[mid] > x)
//             high = mid -1;
//         else
//             low = mid + 1;
//     }
//     return -1;
// }

// overloaded version
// int binarySearch(int *arr, int low, int high, int x) {
//     // int low = 0, high = n-1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] == x) return mid;
//         else if (arr[mid] > x)
//             high = mid -1;
//         else
//             low = mid + 1;
//     }
//     return -1;
// }

// int indexOfFirst (int *arr, int n, int x) {
//     int low = 0, high = n-1;
//     if (low > high) return -1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] > x)
//             high = mid -1;
//         else if (arr[mid] < x)
//             low = mid + 1;
//         else {
//             if (mid == 0 || arr[mid -1] != arr[mid])
//                 return mid;
//             else
//                 high =  mid -1;
//         }
//     }
//     return -1;
// }

// int indexOfLast (int *arr, int n, int x) {
//     int low = 0, high = n-1;
//     if (low > high) return -1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] > x)
//             high = mid -1;
//         else if (arr[mid] < x)
//             low = mid + 1;
//         else {
//             if (mid == 0 || arr[mid] != arr[mid+1])
//                 return mid;
//             else
//                 low =  mid +1;
//         }
//     }
//     return -1;
// }

// int countOccurence (int *arr, int n, int x) {
//     int first = indexOfFirst(arr, n, x);
//     if (first == -1) return -1;
//     else 
//         return(indexOfLast(arr,n,x) - first + 1);
// }

// // count ones in a sorted binary array
// int countOnes(int *arr, int n) {
//     int low =0, high = n-1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] == 0)
//             low = mid +1;
//         else {
//             if (mid == 0 || arr[mid -1] == 0)
//                 return (n - mid);
//             else
//                 high = mid - 1;
//         }
//     }
//     return 0;
// }

// search in an infinite sorted array
// int searchInfinite(int *arr, int x) {
//     if (arr[0] == x) return 0;
//     int i = 1;
//     while (arr[i] < x)
//         i *= 2;
//     if (arr[i] == x) return i;
//     return binarySearch(arr, i/2 + 1,i - 1, x);
//     return -1;
// }

// finding  floor of square root efficiently
// int root (int x) {
//     int low = 1, high = x, ans = -1;
//     while(low <= high) {
//         int mid = (low + high)/2;
//         int msq = mid*mid;
//         if (msq == x) return mid;
//         else if(msq > x)
//             high = mid -1;
//         else {
//             low = mid + 1;
//             ans = mid;
//         }
//     }
//     return ans;
// }

// search in sorted rotated array
// int searchSorted (int *arr, int n ,int x) {
//     int low = 0, high = n-1;

//     while(low <= high) {
//         int mid = (low + high)/2;
//         if (arr[mid] == x) return mid;

//         // if left half is sorted
//         if (arr[low] < arr[mid]) {
//             if (x >= arr[low] && x < arr[mid])
//                 high = mid-1;
//             else 
//                 low = mid+1;
//         }
//         else {
//             if (x > arr[mid] && x <= arr[high])
//                 low = mid+1;
//             else
//                 high = mid-1;
//         }
//     }
//     return -1;
// }

//find the peak element i.e. greater than its neighbours
// if leftmost el, check element after it, if rightmost, check before it
// efficient - check the middle element
// if middle one is greater than both left-right nbd, then middle is peak
// if left one is greater than middle, there must be a peak element on left
// if right one is greater than middle, there must be a peak element on right
int getAnyPeak (int *arr, int n) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = (low +high)/2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
            return mid;
        if (mid > 0 && arr[mid-1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

// minimize the maximum pages allocated between k students, 1 stud can read only contiguos books

int main() {

    // int arr[] = {1,5,6,6,6,8,9,9};
    // int arr[] = {10,20,20,40,7,8,9};
    // int arr[] = {0,0,0,0,1,1,1,1,1};

    // cout << binarySearch(arr, 5, 8);
    // cout << indexOfFirst(arr, 8, 6);
    // cout << indexOfLast(arr, 8, 6);
    // cout << countOccurence(arr, 8, 6);
    // cout << countOnes(arr,9);
    // cout << root(9802);

    // cout << searchInfinite(arr, 6);
    // cout<< searchSorted(arr,7,16);

    int arr[] = {5, 10, 20, 40, 60, 80, 70};
    cout << arr[getAnyPeak(arr, 7)];
    return 0;
}