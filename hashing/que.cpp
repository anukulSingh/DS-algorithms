#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>

using namespace std;


// find count of distinct elements in an array
int countDistinct (int *arr, int n) {
    unordered_set <int> us (arr, arr + n);
    return us.size();
}

// finding frequencies of elements in an array
void countFreq (int *arr, int n) {
    unordered_map <int, int> mp;
    for (int i = 0; i < n ; ++i) 
        mp[arr[i]]++;
    for (pair <int, int> x: mp)
        cout << x.first << " "<< x.second << "\n";
}

// finding no of elements that are common in two arrays
// if
//TC - O(m+n) AS - O(m)
int intersect (int *a, int *b, int m, int n) {
    unordered_set <int> s(a, a+m);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s.find(b[i]) != s.end()) {
            res++;
            s.erase(b[i]); // erases the value from the set
        }
    }    
    return res;
}

// count all distinct elements in two unsorted arrays
// TC & AS - O(m+n)
int unionEl (int *a, int *b, int m, int n) {
    unordered_set <int> s(a, a+m);
    for (int i = 0; i < n; ++i) {
        s.insert(b[i]);
    }
    return s.size();
}

// for unsorted array, check if a pair exists with a given sum
// for sorted array, we use two pointer approach
bool isPair (int *arr, int n, int sum) {
    unordered_set <int> h;
    for (int i = 0; i < n; ++i) {
        if (h.find(sum - arr[i]) != h.end())
            return true;
        else 
            h.insert(arr[i]);
    }
    return false;
} 

// finding subarray with zero sum
// keep calculating the prefix sum and put them in array, if at some pt, two pre_sum are same, then sum of few prev eles are 0
bool isZeroSum (int *arr, int n) {
    unordered_set <int> us;
    int pre_sum = 0;
    for (int i = 0; i < n; ++i) {
        pre_sum += arr[i];
        if (pre_sum == 0) return true;
        if (us.find(pre_sum) != us.end()) {
            return true;
        }
        us.insert(pre_sum);
    }
    return false;
}

// find subarray with given sum, elements are all integers
bool isGivenSum (int *arr, int n, int sum) {
    unordered_set <int> us;
    int pre_sum = 0;
    for (int i = 1; i < n; ++i) {
        pre_sum += arr[i];
        if (pre_sum == sum) return true; // vvi for corner case, subarray starting with index 0, not caught by the algo
        if (us.find(pre_sum - sum) != us.end()) {
            return true;
        }
        us.insert(pre_sum);
    }
    return false;
}

// length of the longest subarray with given sum
// keep track of the index of the prefix sum too, then we can do it
int longestSubSum (int *arr, int n, int sum) {
    unordered_map<int, int> m;
    int pre_sum = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        pre_sum += arr[i];
        if (pre_sum == sum) res = i + 1; // if our subarray starts with 0 index, then prefix sum is at 1
        if (m.find(pre_sum) == m.end()) // no point inserting the same pre sum, as it indicates 0 subarray sum
            m.insert({pre_sum, i});
        if (m.find(pre_sum - sum) != m.end()) {
            res = max(res, i - m[pre_sum - sum]);
        }
    }
    return ans;
}

// count distinct nos in every window of array
void printDistinct (int *arr, int n, int k) {
    map <int, int> mp;
    for (int i = 0; i < k; ++i)
        mp[arr[i]]++;
    cout << mp.size() << " ";
    for (int i = k; i < n; ++i) {
        mp[arr[i-k]]--;
        if (mp[arr[i-k]] == 0)
            mp.erase(arr[i-k]);
        mp[arr[i]]++;
        cout << mp.size() << " ";
    }
}

// elements with more than n/k ocuurences
// thi soln is costly if n is very very large and k is very small
void printNbyK (int *arr, int n, int k) {
    unordered_map <int, int> um;
    for (int i = 0; i < n; ++i)
        um[arr[i]]++;
    for (auto &e: um)
      if (e.second > n/k)
        cout << e.first <<" ";
}

// // better soln for large inputs
// void printNbyK(int *arr, int n, int k) {

// }
int longestSub (int *arr, int n) {
    unordered_set<int> us (arr, arr+n);
    int res = 1;
    for (int x: us) {
        if (us.find(x-1) == us.end()) {
            int curr = 1;
            while (us.find(x + curr) != us.end())
                curr++;
            res = max(res, curr);
        }
    }
    return res;
}
int main() {
    // int arr[] = {15, 16, 27, 27, 28, 15};
    // cout << countDistinct(arr, 6);

    // int arr[] = {10,15,10,20,2,20,10,3,2};
    // countFreq (arr, 9);

    // int a[] = {10, 20,10, 30};
    // int b[] = {20, 10, 10, 40, 30};
    // cout << intersect(a, b, 4, 5);

    // int a[] = {10, 20,10, 30};
    // int b[] = {20, 10, 10, 40, 30};
    // cout << unionEl(a, b, 4, 5);

    // int arr[] = {10,3,4,78};
    // isPair(arr, 4, 81) ? cout << "Present" : cout << "Absent";
    // return 0;

    // int arr[] = {10, 5, 4,-3,-1, 56,4};
    // isZeroSum(arr,7) ? cout << "Present" : cout << "Absent";

    // int arr[] = {10, 10, 5, 3, 20, 5};
    // printDistinct(arr,6,4);

    // int arr[] = {10,20,30,10,10,20,10};
    // printNbyK(arr, 7, 3);

    int arr[]= {1,3,9,2,8,2};
    cout << longestSub(arr, 6);
}