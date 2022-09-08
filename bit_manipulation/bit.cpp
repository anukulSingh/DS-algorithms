#include <bits/stdc++.h>
#define FOR(n) for(int i = 0; i < n; ++i);

using namespace std;

// check if kth bit is set

// using left shift
// bool iskthBitSet(int n, int k) {
//     if (n & (1 << (k - 1)))
//         return true;
//     else 
//         return false;
// }

// using right shift
// bool iskthBitSet(int n, int k) {
//     if ((n >> (k - 1)) & 1) 
//         return true;
//     else 
//         return false;
// }



// count the set bits using look up table method
// theta(1)

int table[256];
void initialize() {
    table[0] = 0;
    for(int i = 1; i < 256; ++i) {
        table[i] = (i & 1) + table[i/2];
    }
}
int count_set(int n) {
    int res = table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    n = n >> 8;
    res = res + table[n & 0xff];
    return res;
}

// check whether given no is a power of 2
// any power of 2 has only one set bit

// bool isPow2(int n) {
//     return (n != 0) && ((n & (n - 1)) == 0);
// }

// checking nos in an array whuch ahs odd occurence
// int findOdd (int *arr, int n) {
//     int res = 0;
//     for (int i = 0; i < n; ++i)
//         res = res ^ arr[i];
//     return res;
// }

// checking two  numbers wich has odd occurence
// void findTwoOdd(int arr[], int n)
// {
    
//         int xors = 0, res1 = 0, res2 = 0; 
        
//         for (int i = 0; i < n; i++) 
//         xors = xors ^ arr[i]; 
  
   
//         int sn = xors & (~(xors - 1)); 
  
    
//         for (int i = 0; i < n; i++) 
//         { 
//             if ((arr[i] & sn) != 0) 
//                 res1 = res1 ^ arr[i]; 
//             else
//                 res2 = res2 ^ arr[i]; 
//         } 
        
        
//         cout <<  res1 << " " << res2;
// }

// print the power set of a string
void printPowerSet(string str) {
    int n = str.length();
    int powSize = pow(2,n);
    for (int counter = 0; counter < powSize; ++counter)  {
        for (int j = 0; j < n; ++j) 
            if (counter & (1 << j))
                cout << str[j];
        cout<<"\n";
    }
}

int main() {
    
    // int n = 5, k = 4;
    // iskthBitSet(n, k) ? cout << "SET" : cout << "Not a SET";

    // initialize();
    // cout << count_set(9);

    // isPow2(9) ? cout << ":)" : cout << ":(";
    // int arr[] = {3,4,3,4,5,4,4,6,7,7};
    // // cout << findOdd(arr, 5);
    // findTwoOdd(arr,10);

    string str = "abcd";
    printPowerSet(str);
    return 0;
}