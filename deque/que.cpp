#include <iostream>
#include <deque>

using namespace std;

void printKMax (int *arr, int n, int k) {
    deque <int> dq;
    for (int i = 0; i < k ; ++i) {
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        dq.push_back(i);
        }
    }
    for (int i = k; i < n; ++i) {
        cout << arr[dq.front()] << " ";
            
    }
}
// max of all subarrays of size k
// there are n-k+1 total subarrays possible
int main() {

    return 0;
}