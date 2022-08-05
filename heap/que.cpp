#include <iostream>
#include <queue>
using namespace std;

// sort a k sorted array
// array is somewhat sorted
// in th out sorted arry, an el at index i will be present bw i-k and i+k 
// naive app will be to sort it

// purchasing maximum items (count), given a range of prices and a fixed sum to be spent
// purchase should be done within the given sum; one item can be picked once
// naive way will be to sort the array and then traverse
// O(n) + O(res logn) --eff way

// int purchaseMaxItems (int *costs, int n, int sum) {
//     priority_queue<int, vector <int>, greater<int> > pq;
//     int res = 0;
//     for (int i = 0; i < n ; ++i)
//         pq.push(costs[i]);
//     for (int i = 0; i < n; ++i) {
//         if (pq.top() <= sum) {
//             sum -= pq.top();
//             pq.pop();
//             res++;
//         } else break;
//     }
//     return res;
// } 



// get largest k elements
// using max_heap , we can do this easily
// TC is O(n + k log n)
// using min_heap, we can maintain k largest eles till any point
// make a min_heap of first k elements, traverse from k+1th
// if curent el is smaller than top of heap, ignore it
// else remove the top element and push this el to heap
// after last, all the k largest will be in the heap
// O(k + (n-k) log k)
// using this, we can keep track of k largest eles at any given point
void kLargest(int *arr, int n, int k) {
    priority_queue<int, vector <int>, greater<int> > pq;
    for (int i = 0; i < k; ++i)
        pq.push(arr[i]);
    for (int i = k; i <n; ++i) {
        if (arr[i] > pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        } else continue;
    }
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

}

int main () {

    // int costs[] = {20, 10, 5, 30, 100};
    // cout << purchaseMaxItems(costs, 5, 35);

    int arr[] = {5, 15, 10, 20, 8, 25, 18};
    kLargest(arr, 7, 3);

    return 0;
}