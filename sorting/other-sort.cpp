#include <iostream>
using namespace std;


// Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.
// Best Case Time Complexity: O(n). Best case occurs when array is already sorted.
// Auxiliary Space: O(1)
// Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.
// Sorting In Place: Yes
// Stable: Yes
void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n-1; ++i) {
        bool swapped = false;

        for (int j = 0; j<n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// in place
// stable
// good for memory intensive resource
// not stable, but can be made so
void selectionSort(int *arr, int n) {

    for (int i =0; i< n-1; ++i) {
        int min_index = i;
        for (int j = i+1; j < n; ++j) 
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[min_index], arr[i]);
    }
}

void insertionSort(int *arr, int n) {
    for (int i =1; i< n; ++i) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


// 1 Cycle sort - O(n^2) worst case algo
// least memory writes among all others, useful where mem-write is costly
// In place and unstable
// solve ques like min swaps reqd to sort an array
void cycleSort() {
    for (int cycle = 0; cycle < n-1; ++cycle) {
        int item = arr[cycle];
        int pos = cycle;
        for (int i = cycle+1; i < n; ++i) {
            if (arr[i] < item) pos++;
        }
        swap(item, arr[pos]);
        while (pos != cycle) {
            pos = cycle;
            for (int i = cycle+1; i < n; ++i) {
                if (arr[i] < item) pos++;
            }
            swaps(item, arr[pos]);
        }
    }
}

// if data is uniformly distributed bw intervals till max element, then O(n) TC
void bucketSort () {
    int max_value = *max_element(arr, arr+n);
    max_value++;
    vector <int> bkt[k];
    for (int i = 0; i < n; ++i) {
        int bi = (k*arr[i])/max_value;
        bkt[bi].push_back(arr[i]);
    }
    // sort each bucket
    for (int i = 0; i < k; ++i) {
        sort(bkt[i].begin(), bkt[i].end());
    }
    int index = 0;
    // join buckets
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < bkt[i].size(); ++j)
            arr[index++] = bkt[i][j];
}
int main () {


    return 0;
}