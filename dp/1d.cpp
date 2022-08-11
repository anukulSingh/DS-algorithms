#include <iostream>

using namespace std;


// staircase problem
// How many ways you can reach nth stair from 0the stair , making a jump of 1 or 2
// int dp[10001];
// int mod = 1e9+7;
void stair() {
    dp[1] = 1 // 1 way for 1st
    dp[2] = 1 // 2 ways for 2nd
    for (int i = 3; i <= 1000; ++i)
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
}

// important recursive approach
int dp[100001];
int stairs(int n) {
    if (n <= 2) return n;
    if (dp[n] != 0) return dp[n];
    dp[n] = stairs(n-1) + stairs(n-2);
    return dp[n];
}

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

}