#include <iostream>
using namespace std;


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