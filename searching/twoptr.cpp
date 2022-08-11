#include <iostream>
#include <vector>

using namespace std;

// int l =0, r = n-1;

// pair with given sum check
// bool isPair(int *arr,int n, int l,int r, const int x) {
//     while (l < r) {
//         if (arr[l] + arr[r] == x) return true;
//         else if (arr[l] + arr[r] > x)
//             r--;
//         else 
//             l++;
//     }
//     return false;
// }

// triplet with given sum check
// bool isTriplet(int *arr,int n, int l,int r, const int x) {
//     for (int i = 0; i< n; ++i) {
//         if (isPair(arr,n, i+1, n-1, x-arr[i]))
//             return true;
//     }
//     return false;
// }



// find repeating number in the sequence
// max_arr <= n-2
// given only 1 el repeats
// we can sort and check linearly if any element appears
// works in nlog n, but modifies the array
// one efficient way is of O(n) TC and O(n) AS as follows:
// int findRepeating (int *arr, int n) {
//     bool flag[n] = {false};
//     for (int i = 0; i < n; ++i) {
//         if (flag[arr[i]])
//             return arr[i];
//         flag[arr[i]] = true;
//     }
//     return -1;
// }

// second eff method is to use O(1) AS
// here min ele in sequence is 1
// we are going to form a visual loop, in which first element is the one we are looking for
// start from arr[0], take its value and use it as index for next element, at some point,
// it will go backwards forming chain
// for this, we use a two-phase algorithm
// int findRepeating(int *arr, int n) {
//     int slow= arr[0], fast = arr[0];
//     // in first phase, slow moves 1 block at a time, fast moves two blocks at a time (front/back)
//     // they are going to meet at some point i.e. slow = fast
//     do {
//         slow = arr[slow];
//         fast = arr[arr[fast]];
//     } while (slow != fast);
//     //keep fast at same location, but move slow to start
//     slow = arr[0];
//     // in second phase, simple moving will get us to our result
//     while (slow != fast) {
//         slow = arr[slow];
//         fast = arr[fast];
//     }
//     return slow;
// }

// to handle the 0 case too, treat every el as increased by 1
// int findRepeatinginc(int *arr, int n) {
//     int slow= arr[0]+1, fast = arr[0]+1;
//     // in first phase, slow moves 1 block at a time, fast moves two blocks at a time (front/back)
//     // they are going to meet at some point i.e. slow = fast
//     do {
//         slow = arr[slow]+1;
//         fast = arr[arr[fast] + 1] +1;
//     } while (slow != fast);
//     //keep fast at same location, but move slow to start
//     slow = arr[0]+1;
//     // in second phase, simple moving will get us to our result
//     while (slow != fast) {
//         slow = arr[slow] + 1;
//         fast = arr[fast] + 1;
//     }
//     return slow - 1;
// }

// here is another prob, finding both repeating and missing
// here we use the XOR technique
void repeating_missing (vector <int> &arr) {
    int n = arr.size();
    int mixture = 0;
    for (int i = 0; i < n; ++i)
        mixture ^= arr[i];
    for (int i = 1; i <= n; ++i)
        mixture ^= i;
    int rsb = mixture & ~(mixture - 1);
    int x = 0, y= 0;
    for (int val: arr) {
        if ((val & rsb) == 0)
            x ^= val;
        else 
            y ^= val;
    }
    for (int i = 1; i <= n; ++i) {
        if ((i & rsb) == 0) {
            x = x^ i;
        }
        else {
            y = y ^i;
        }
    }
    for (int val: arr) {
        if (val == x) {
            cout << "Missing: " << y << "\n";
            cout << "Repeating: " << x;
            break;
        }
        else if (val == y) {
             cout << "Missing: " << x << "\n";
             cout << "Repeating: " << y;
             break;
        }
    }

}


int main() {
    // int arr[] = {2,3,5,7,8};
    // isPair(arr, 6, 13) ? cout << "Yes" : cout << "Nope";
    // isTriplet(arr,5,0,4, 10) ? cout << "Yes" : cout << "Nope";

    // int arr[] = {0,2,1,3,2,2};
    // cout << findRepeating(arr, 6);

    // same but 0 is not here
    // int arr[] = {1,3,2,4,6,5,7,3};
    // cout << findRepeating(arr, 8);

    // 0 included
    // int arr[] = {0,2,1,3,2,2};
    // cout << findRepeatinginc(arr, 6);

    vector <int> arr{1,3,4,5,1,6,2};
    repeating_missing(arr);
}