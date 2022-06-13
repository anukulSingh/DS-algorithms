#include <iostream>
using namespace std;

// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes
// void bubbleSort(int *arr, int n) {
//     for (int i = 0; i < n-1; ++i) {
//         bool swapped = false;

//         for (int j = 0; j<n-i-1; ++j) {
//             if (arr[j] > arr[j+1]) {
//                 swap(arr[j],arr[j+1]);
//                 swapped = true;
//             }
//         }
//         if (swapped == false)
//             break;
//     }
// }

// in place
// stable
// good for memory intensive resource
// not stable, but can be made so
// void selectionSort(int *arr, int n) {

//     for (int i =0; i< n-1; ++i) {
//         int min_index = i;
//         for (int j = i+1; j < n; ++j) 
//             if (arr[j] < arr[min_index])
//                 min_index = j;
//         swap(arr[min_index], arr[i]);
//     }
// }

// void insertionSort(int *arr, int n) {
//     for (int i =1; i< n; ++i) {
//         int key = arr[i];
//         int j = i-1;
//         while (j >= 0 && arr[j] > key) {
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = key;
//     }
// }

// merge two sorted arrays
// theta(m+n) TC, const AS
// void merge(int *a, int *b, int m, int n) {
//     int i=0,j=0;
//     while(i < m && j < n) {
//         if (a[i] <= b[j]) 
//             cout << a[i++] << " ";
//         else
//             cout << b[j++] << " ";
//     }
//     while (i < m)
//         cout << a[i++] << " ";
//     while (j < n)
//         cout << b[j++] << " ";
// }

// merge function of merge sort
// elements from low to mid are sorted, them els from mid+1 to high are sorted
// Both TC and AS is theta(n)
// void merge(int *a, int low, int mid, int high) {

//     // setting up auxiliary array
//     int n1 = mid - low +1, n2 = high - mid;
//     int left[n1], right[n2];
//     for (int i =0; i < n1; ++i)
//         left[i] = a[low + i];
//     for (int i =0; i < n2; ++i)
//         right[i] = a[mid + i + 1];

//     // standard merge logic
//     int i =0, j =0, k = low;
//     while (i < n1 && j < n2) {
//         if (left[i] <= right[j])
//             a[k++] = left[i++];
//         else
//             a[k++] = right[j++];
//     }

//     while (i < n1)
//         a[k++] = left[i++];
//     while (j < n2)
//         a[k++] = right[j++];

// }

// l is 0 index, r is last index
// at each level theta(n) work is done
// there are [log2 n] + 1 levels (ceiling)
// so TC is theta(n log n)
// AS is theta(n), each merge func requires theta(n) at each level, but gets deallocated too
// void mergeSort(int *arr, int l, int r){
//     if (r > l) { // at least 2 elements
//         int m = l + (r - l)/2;  // mid element, same as (l+r)/2, but this prevents arithmetic overflow for large arrays
//         mergeSort(arr, l, m);  // sort first half
//         mergeSort(arr, m+1, r);  // sort second half
//         merge(arr,l,m,r);   // merge two sorted halves
//     }
// }



// Intersection of two sorted arrays
// common elements
// void intersection (int *a, int *b, int m, int n) {
//     int i =0, j = 0;
//     while (i < m && j < n) {
//         if (i > 0 && a[i] == a[i-1]) {
//             i++;
//             continue;
//         }
//         if (a[i] < b[j]) i++;
//         else if (a[i] > b[j]) j++;
//         else {
//             cout << a[i] << " ";
//             i++; j++;
//         }
//     }
// }

// Sorted union of two sorted arrays
// using merge func approach
// TC is O(m+n), AS is O(1)
// void unionEl(int *a, int *b, int m, int n) {
//     int i =0, j = 0;
//     while (i < m && j < n) {
//         if (i > 0 && a[i] == a[i-1]) {
//             i++;
//             continue;
//         }
//         if (j > 0 && b[j] == b[j-1]) {
//             j++;
//             continue;
//         }
//         if (a[i] < b[j]) {
//             cout << a[i++] << " ";
//         }
//         else if (a[i] > b[j]) {
//             cout << b[j++] << " ";
//         }
//         else {
//             cout << a[i] << " ";
//             i++; j++;
//         }
//     }
//     while (i < m)
//         if (i < m && a[i] != a[i-1])
//             cout << a[i] << " ";
//     while (j < n)
//         if (j > 0 && b[j] != b[j-1])
//             cout << b[j] << " ";
// }

// count inversion in an array
// arr[i], arr[j] is an inversion if i < j && arr[i] > arr[j]
// 0 inversion in asc sorted, n*(n-1)/2 inversions in desc sorted array
// using concept of merge sort
// TC O(n log n) & AS O(n)

// int countAndMerge(int *a, int low, int mid, int high) {

//     // setting up auxiliary array
//     int n1 = mid - low +1, n2 = high - mid;
//     int left[n1], right[n2];
//     for (int i =0; i < n1; ++i)
//         left[i] = a[low + i];
//     for (int i =0; i < n2; ++i)
//         right[i] = a[mid + i + 1];

//     // standard merge logic
//     int res = 0;
//     int i =0, j =0, k = low;
//     while (i < n1 && j < n2) {
//         if (left[i] <= right[j])
//             a[k] = left[i++];
//         else {
//             a[k] = right[j++];
//             res += (n1 - i);
//         }
//     }

//     while (i < n1)
//         a[k++] = left[i++];
//     while (j < n2)
//         a[k++] = right[j++];
//     return res;

// }
// int countInversion (int *arr, int l, int r) {
//     int res= 0;
//     if (l < r) {
//         int m = l + (r-l)/2;
//         res += countInversion(arr, l, m);
//         res += countInversion(arr, m+1, r);
//         res += countAndMerge(arr,l, m, r);
//     }
//     return res;
// } 
int main() {
    // int arr[]= {10,30,2,4,32,1,0};
    // int b[] = {1,12};
    // bubbleSort(arr,6);
    // selectionSort(arr, 6);
    // insertionSort(arr,7);
    
    // int a[]={10,15,20,40};
    // int b[]={5,6,6,10,15, 60};
    // merge(a,b,4,6);

    // int arr[] = {10, 20, 40, 20, 30};
    // merge(arr, 0, 2, 4);
    // for (int &x: arr)
    //     cout << x << " ";

    // int arr[] = {10,5,30,15,7};
    // mergeSort(arr,0,4);
    // for (int &x: arr)
    //     cout << x << " ";

    // int a[] = {10, 20, 20, 40, 60};
    // int b[] = {2,20,20,20, 60};
    // intersection(a, b, 5,5);

    // int a[] = {10, 20, 20, 40, 60};
    // int b[] = {2,20,20,20, 60};
    // unionEl(a, b, 5,5);

    int arr[] = {2,4,1,3,5};
    cout << countInversion(arr, 0, 4);

}