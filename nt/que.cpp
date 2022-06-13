#include <iostream>
#define rep(i,a,b) for (i = a; i < b; ++i);
#define repl(i,a,b) for (i = a; i <= b; ++i);
typedef long long ll;
using namespace std;

const int n = 1e6 + 1;


// answer nCr queries in O(1)

// array to store inverse from 1! to n!
ll factorialNumInverse[n+1];
// array to pre compute inverse of 1 to n
ll naturalNumInverse[n+1];
// array to store factorial of first n numbers
ll fact[n+1];

// function to pre compute inverse of numbers
void InverseOfNumber (ll p) {
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    int i;
    repl(i,2,n) {
        naturalNumInverse[i] = naturalNumInverse[p % i]* (p - p/i) % p;
    }
}
// function to pre compute inverse of facts from 1! to n!
void InverseOfFactorial (ll p) {
    int i;
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i-1]) % p;
}
// calculates fact from 1! to n!
void factorial(ll p) {
    fact[0] = 1;
    int i;
    rep(i,0,n+1) {
        fact[i] = (fact[i-1] * i) % p;
    }
}
// return ncr % p in O(1)
ll binomial (ll n, ll r, ll p) {
    return ((fact[n] * factorialNumInverse[r]) % p * factorialNumInverse[n-r]) % p;
}
int main () {
    ll p = 1e9 + 7;
    InverseOfNumber(p);
    InverseOfFactorial(p);
    factorial(p);

    ll n = 15, r = 4;
    cout << binomial(n,r,p);
}