#include <iostream>
#include <algorithm>
using namespace std;

// maxCircularSum = arr_sum - normalMinSum
// normalMinSum = -(normalMaxSum in an inverted array)
// inverted array means all elements multiplied by -1

// longest increasing subsequence ina circular array , used DP

// print a circular array starting with given index
void print(char *a, int n, int index ) {
    for (int i = index;  i < index+n; ++i)
        cout << a[(i % n)] << " ";
}

// max sum of consecutive differences in a circular array, rearrangement can be done
// we can sort the array, then rearrange as such
// first and last adjacent, second and last second together and so on
// if we take consec sum of such an array, it would be maximum (greedy)
int maxConsecutiveDiffSum(int *arr, int n) {
    sort (arr, arr+n);
    int l = 0, r = n-1;
    int sum = 0;
    int b[n],k =0;
    while (l < r) {
        b[k++] = arr[l++];
        b[k++] = arr[r--];
    }
    // for odd no of elements
    if (n&1) {
        b[k] = arr[l];
    }

    for(int i = 0; i <n-1; ++i)
        sum+= abs(b[i]- b[i+1]);
    sum+= abs(b[n-1] - b[0]); // for circular condition
    return sum;
}

int main () {

    // char arr[] = {'a','b','c','d','e','f'};
    // int n = 6;
    // print(arr,n,3);

    int arr[] = {4,2,1,8};
    cout << maxConsecutiveDiffSum(arr, 4);
    return 0;
}