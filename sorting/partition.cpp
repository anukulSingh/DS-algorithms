#include <iostream>
using namespace std;


// Naive partition (stable)
// TC & AS O(n)
// given an index, make smaller els befor it, and greater after it (any order)
int partition (int *arr, int l, int h, int p) {
    int temp[h - l + 1], index = 0;
    // putting smaller elements
    for (int i = l; i <= h; ++i) {
        if (arr[i] <= arr[p] && i != p) {
            temp[index] = arr[i];
            index++;
        }
    }
    int res = index;
    temp[index++] = arr[p];
    // putting larger elements
    for (int i = l;i <h; ++i) {
        if (arr[i] > arr[p]) {
            temp[index] = arr[i];
            index++;
        }
    }
    for (int i =l; i <=h; ++i)
        arr[i] = temp[i-l];

    return res;
}

// lomuto partition ensures that pivot is at correct place,
// while hoare simply partition array into two parts

// Lomuto partition AS here is constant
// generally pivot is at last in lomuto
// at any time , we aintain two windows (smaller than pivot, and larger)
// i denotes end of smaller elements window
int lpartition (int *arr, int l, int h) {

    // swap(arr[pivot], arr[h]);   // to keep pivot at last if not at last
    int pivot = arr[h];

    int i =  l -1;   // i keeps track of smaller elements
    for (int j = l; j <= h-1; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1; // returns new index of pivot
    
}

/** Hoare's partition
 works better than lomuto, but
 elements till j are smaller than pivot
 normally pivot is the first element here
 it is unstable like lomuto, unlike naive

 at any moment, we ensure that elements from l to i are smaller than pivot
 and elements from j to h are greater than or equal to pivot
**/
int hpartition(int *arr, int l, int h) {
    int pivot = arr[l];
    int i = l-1, j = h+1;
    while (true) {
        do {
            i++;
        }while (arr[i] < pivot); // i stops where it is gte pivot
         do {
            j--;
        }while (arr[j] > pivot); // j stops where it is lte pivot
        if (i >= j) return j;
        swap (arr[i], arr[j]);
    }
}

// Quick sort points
// Divide & conquer algorithm
//worst case TC O(n^2)
// but faster becuase of: In-place (no aux. array), cache friendly, av TC O(n log n), Tail recursive
// partition is key function (naive, lomuto, hoare)
// in mergesort, merge func is complex, here partition is complex
void qsort (int *arr, int l, int h) {
    if (l < h) {
        int p = lpartition(arr, l, h);
        qsort(arr, l, p-1);
        qsort(arr, p+1, h);
    }
}
int main() {

    // int arr[] = {5,13,6,9,12,11,8};
    // int n= 7,p =3;
    // cout << arr[3] << " new index is: "<< partition(arr, 0, n-1, p) << "\n";
    // for (int &x: arr)
    //     cout << x << " ";

    // int arr[] = {10,80,30,90,40,50,51,70};
    // int n= 8,p = 6;
    // cout << arr[p] << " new index is: "<< lpartition(arr, 0, n-1, p) << "\n";
    // for (int &x: arr)
    //     cout << x << " ";

    // return 0;

    // int arr[] = {5,3,8,4,2,7,1,10};
    // int n= 8;
    // cout <<" first half end at index: "<< hpartition(arr, 0, n-1) << "\n";
    // for (int &x: arr)
    //     cout << x << " ";

    int arr[] = {5,3,8,4,2,7,1,10};
    qsort(arr, 0, 7);
    for (int &x: arr)
        cout << x << " ";

    return 0;
}
