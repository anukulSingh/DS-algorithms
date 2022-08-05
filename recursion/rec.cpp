#include <bits/stdc++.h>
using namespace std;

// factorial
// int fact(int n, int k) {
//     if (n == 0 || n == 1 ) return k;
//     return fact(n-1, k*n);
// }
// // fibonacci
// int fib (int n) {
//     if ( n <= 1 ) return n;
//     return fib(n-1) + fib(n-2);
// }

// // sum of first n natural no 
// int sumRec(int n) {
//     if (n == 0) return 0;
//     return n + sumRec(n-1);
// }
// int sumRectail(int n, int k) {
//     if (n == 0) return k-1;
//     return sumRectail(n-1, n+k);
// }

// checking string for an anagram
// bool isPalindrome(String &str, int start, int end) {
//     if (start >= end) return true;
//     return (str[start] == str[end]) && isPalindrome(str, start+1, end-1);
//
// int getSum(int n) {
//     if (n < 10) return n;
//     else return getSum(n/10) + n % 10;
// }


// Rope cutting problem 
// int max(int i , int j, int k) {
//     return i > j? (i > k? i: k): (j > k? j: k);
// }
// int maxPiece(int n, int a ,int b, int c) {
//     if (n == 0) return 0;
//     if (n < 0) return -1;
//     int res = max(maxPiece(n-a,a,b,c),maxPiece(n-b,a,b,c),maxPiece(n-c,a,b,c));
//     if (res == -1) return -1;
//     return res + 1;
// }

// SUbsets of a string
// we can generate subsets of "ABC" from "AB" a nd AB from A
void subset(string &s, string curr = "", int i = 0) {
    if (i == s.length()){
        cout << curr<< " ";
        return;
    }
    subset(n,curr,i+1);
    subset(n, curr + s[i], i+1);
}


int main() {
    // cout << fact(6,1);
    // cout << fib(20);
    // cout << sumRec(5);
    // char str[] = "abba";
    // isPalindrome(str, 0,3);
    // res ? cout << ":)" : cout << ":(";
    // cout << sumRectail(10, 1);

    // cout << getSum(567);
    // cout << maxPiece(5,2,5,1);

    string str = "ABC";
    cout << subset(str,0);
}