#include <iostream>
#include <climits>
using namespace std;

void largestThree(int *arr, int n) {
    int first,second,third;
    if (n < 3) {
        cout << "Invalid input";
        return;
    }
    first = second = third = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third) {
            third = arr[i];
        }
    }
    cout << first << endl << second << endl << third;
}
int main() {

}