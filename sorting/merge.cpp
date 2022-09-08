#include <iostream>
using namespace std;



// merge two sorted arrays
// theta(m+n) TC, const AS
void merge(int *a, int *b, int m, int n) {
    int i=0,j=0;
    while(i < m && j < n) {
        if (a[i] <= b[j]) 
            cout << a[i++] << " ";
        else
            cout << b[j++] << " ";
    }
    while (i < m)
        cout << a[i++] << " ";
    while (j < n)
        cout << b[j++] << " ";
}

// merge function of merge sort
// elements from low to mid are sorted, them els from mid+1 to high are sorted
// Both TC and AS is theta(n)
void merge(int *a, int low, int mid, int high) {

    // setting up auxiliary array
    int n1 = mid - low +1, n2 = high - mid;
    int left[n1], right[n2];
    for (int i =0; i < n1; ++i)
        left[i] = a[low + i];
    for (int i =0; i < n2; ++i)
        right[i] = a[mid + i + 1];

    // standard merge logic
    int i =0, j =0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1)
        a[k++] = left[i++];
    while (j < n2)
        a[k++] = right[j++];

// }

// l is 0 index, r is last index
// at each level theta(n) work is done
// there are [log2 n] + 1 levels (ceiling)
// so TC is theta(n log n)
// AS is theta(n), each merge func requires theta(n) at each level, but gets deallocated too
void mergeSort(int *arr, int l, int r){
    if (r > l) { // at least 2 elements
        int m = l + (r - l)/2;  // mid element, same as (l+r)/2, but this prevents arithmetic overflow for large arrays
        mergeSort(arr, l, m);  // sort first half
        mergeSort(arr, m+1, r);  // sort second half
        merge(arr,l,m,r);   // merge two sorted halves
    }
}



// Intersection of two sorted arrays
// common elements
void intersection (int *a, int *b, int m, int n) {
    int i =0, j = 0;
    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i-1]) {
            i++;
            continue;
        }
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }
}

// Sorted union of two sorted arrays
// using merge func approach
// TC is O(m+n), AS is O(1)
void unionEl(int *a, int *b, int m, int n) {
    int i =0, j = 0;
    while (i < m && j < n) {
        if (i > 0 && a[i] == a[i-1]) {
            i++;
            continue;
        }
        if (j > 0 && b[j] == b[j-1]) {
            j++;
            continue;
        }
        if (a[i] < b[j]) {
            cout << a[i++] << " ";
        }
        else if (a[i] > b[j]) {
            cout << b[j++] << " ";
        }
        else {
            cout << a[i] << " ";
            i++; j++;
        }
    }
    while (i < m)
        if (i < m && a[i] != a[i-1])
            cout << a[i++] << " ";
    while (j < n)
        if (j > 0 && b[j] != b[j-1])
            cout << b[j++] << " ";
}

// count inversion in an array
// arr[i], arr[j] is an inversion if i < j && arr[i] > arr[j]
// 0 inversion in asc sorted, n*(n-1)/2 inversions in desc sorted array
// using concept of merge sort
// TC O(n log n) & AS O(n)

  long long countAndMerge(long long arr[], long long l, long long m , long long r) {
      long long j = m + 1;
      long long count = 0;
      
      for (long long i = l; i <= m; ++i) {
          while (j <= r && arr[i] > arr[j]) {
              j++;
          }
          count += (j - (m + 1));
      }
      
      // merge logic
      long long left = l, right = m + 1;
      vector<long long> temp;
      while (left <= m && right <= r) {
          if (arr[left] <= arr[right]) {
              temp.emplace_back(arr[left++]);
          } else {
              temp.emplace_back(arr[right++]);
          }
      }
      
      while (left <= m)
        temp.emplace_back(arr[left++]);
      while (right <= r) {
          temp.emplace_back(arr[right++]);
      }
      
      for (int i = l; i <= r; ++i) {
          arr[i] = temp[i - l];
      }
      
      return count;
    }
    long long int countInv(long long arr[], long long l, long long r) {
        long long res = 0;
        if (l >= r) return 0;
        
            long long m = l + (r - l) / 2;
            res += countInv(arr, l, m);
            res += countInv(arr, m+1, r);
            res += countAndMerge(arr, l, m, r);
        
        return res;
    }

// same logic for finding reverse pairs - leetcode
// A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j]
 int merge(int start, int mid,  int end, vector<int> & nums) {
        int j = mid + 1;
        int count = 0;
        for (int i = start; i <= mid; ++i) {
            while (j <= end && nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        
        // standard merge logic
        vector<int> temp;
        int left = start, right = mid + 1;
        while (left <= mid && right <= end) {
            if (nums[left] <= nums[right]) {
                temp.emplace_back(nums[left++]);
            }
            else
                temp.emplace_back(nums[right++]);   
        }
        while (left <= mid)
            temp.emplace_back(nums[left++]);
        while (right <= end)
            temp.emplace_back(nums[right++]);
        
        
        for (int i = start; i <= end; ++i) {
            nums[i] = temp[i - start];
        }
        
        return count;
    }
    int mergeSort(int start, int end, vector<int> & nums) {
        int inv = 0;
        if (start >= end) return 0;
        int mid = start + (end - start) / 2;
        inv += mergeSort(start, mid, nums);
        inv += mergeSort(mid + 1, end, nums);
        inv += merge(start, mid, end, nums);
        return inv;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }


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