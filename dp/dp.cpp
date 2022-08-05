#include <iostream>
#include <cstring>
using namespace std;


// dp memorization for a fibonacci series
// tc reduced from exp to linear
// top - down approach (starts from n)
// int memo[10];
// int fib (int n) {
//     if (memo[n] == -1) {
//         int res;
//         if (n == 0 || n == 1) return n;
//         else {
//             res = fib(n-1) + fib(n-2);
//         }
//         memo[n] = res;
//     }
//     return memo[n];
// }



// dp tabulation
// no recursion overhead, faster, but hard to implement at times
// bottom-up approach
int fib (int n) {
    int f[n+1];
    f[0] = 0; f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}
int main() {

    // memset(memo, -1, sizeof(memo));
    // cout << fib(5);

    int n = 5;
    cout << fib(n);

    return 0;
}