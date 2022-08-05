#include <iostream>
#include <utility>
#include <tuple>
#include <cmath>
#include <vector>

using namespace std;

// count number of digits
// int count_digit(int n) {
// 	return  n > 0 ? (int) (log10 (n) + 1) : (int) (log10 (-n) + 1);
// }

// check for palindrome
// bool isPalindrome(int n) {
// 	int rev = 0;
// 	int temp = n;
// 	while (temp != 0) {
// 		int last_digit = temp % 10;
// 		rev = rev*10 + last_digit;
// 		temp /= 10;
// 	}
// 	return (rev == n);
// }

// factorial implemntation, iterative way is better
// int fact (int n) {
// 	int res = 1;
// 	for (int i = 2; i <= n; ++i) 
// 		res *= i;
// 	return res;
// }

// trailing zeroes in factorial
// int countTrailingZeroes (int n) {
// 	int res = 0;
// 	for (int i = 5; i <= n; i *= 5)
// 		res += n/i;
// 	return res;
// }

// gcd of two numbers  d = (a,b)
// 'or' largest square of size d*d by which we can fill rect a*b
// Euclidean algorithm
// int gcd (int a, int b) {
// 	while (a != b) {
// 		if (a > b)
// 			a = a - b;
// 		else
// 			b = b - a;
// 	}
// 	return a;
// }

// optimized Euclidean algorithm
// O(log(min(a, b)))
// int gcd (int a, int b) {
// 	if (b == 0)
// 		return a;
// 	else 
// 		gcd(b, a % b);
// }

// iterative gcd
// O(log min(a, b))
// int gcdFaster (int a, int b) {
// 	while(b) {
// 		a %= b;
// 		swap(a, b);
// 	}
// 	return a;
// }

// // Extended euclidean algorithm
// int gcdExtended (int a, int b, int &x, int &y) {
// 	 if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     }
//     int x1, y1;
//     int d = gcd(b, a % b, x1, y1);
//     x = y1;
//     y = x1 - y1 * (a / b);
//     return d;
// }
 int gcdExFaster(int a, int b, int &x, int &y) {

    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

// linear diophantine eqn
// 1- finding any one solution if possible
pair<int, int> find_any_solution (int a, int b, int c) {
	int x0 = 1, y0 = 0;
	int g = gcdExFaster(abs(a), abs(b), x0, y0);
	if (c % g) {
		cout << " no possible solutions";
	}
	x0 *= c/g;
	y0 *= c/g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return {x0, y0};
}




// check for prime
// bool isPrime (int n) {
// 	if (n == 1) return false;
// 	if (n == 2 || n == 3) return true;
// 	if (n % 2 == 0 || n % 3 == 0)
// 		return false;
// 	for (int i = 5; i*i <= n; i += 6) 
// 		if (n % i == 0 || n % (i + 2) == 0)
// 			return false;
// 	return true;
// }

// lcm finding, TC same as gcd
// length of the smallest square that can be constructed using one or more rectangular pieces of dim a and b
// int lcm (int a, int b) {
// 	return (a * b)/ gcd(a,b);
// }

// prime factors of a number
// O(sqrt(n))
void printPrimeFactors (int n) {
	if (n <= 1) return;
	while (n % 2 == 0) {
		cout << 2 << " ";
		n /= 2;
	}
	while (n % 3 == 0) {
		cout << 3 << " ";
		n /= 3;
	}

	for (int i = 5; i*i <= n; i += 6) {
		while (n % i == 0) {
			cout << i<< " ";
			n /= i;
		}
		while (n % (i + 2) == 0) {
			cout << (i + 2) << " ";
			n /= (i + 2);
		}
	}
	if  (n > 3)
		cout << n;
}

// divisors of a number in sorted order
// theta(sqrt(n))
// void printDivisors(int n) {
// 	int i;
// 	for (i = 1; i*i < n; ++i)
// 		if (n % i == 0) {
// 			cout << i <<" ";
// 		}
// 		--i;
// 	for ( ;i >= 1; --i)
// 		if (n % i == 0)
// 			cout << n/i << " ";
// }

// Sieve of Erastothenes to print prime numbers
// void sieve(int n) {
// 	vector <bool> isPrime(n+1, true);
// 	for (int i = 2; i*i <= n; ++i) {
// 		if (isPrime[i]) {
// 			for (int j = 2*i; j <= n; j = j + i)
// 				isPrime[j] = false;
// 		}
// 	}
// 	for (int i = 2; i <=n; ++i)
// 		if(isPrime[i])
// 			cout << i << " ";
// }

//optimized sieve O(n loglogn) ~ O(n)
//void sieve(int n) {
	//vector <bool> isPrime(n+1, true);
	//for (int i = 2; i <= n; ++i){
	//	if (isPrime[i]){
	//		cout << i << " ";
		//	for (int j = i*i; j <= n; j = j + i)
			//	isPrime[j] = false;
		//}
	//}
//}

// rule of thumb
//pow(a, n) = 1, if n == 0
//         = pow(pow(a, n/2)), 2), if n > 0 and even
// 		   = pow(pow(a, n-1/2), 2)*a, if n > 0 and odd

// COmputing power  O(log n)
// int power(int x, int n) {
// 	if (n == 0)
// 		return 1;
// 	int temp = power(x, n/2);
// 	temp *= temp;
// 	return (n % 2 == 0) ? temp : temp*x;
// } 

// Iterative power
// Binary exponentiation
// int powerIterative(int x, int n) {
// 	int res = 1;
// 	while (n>0) {
// 		if (n & 1)  // n%2!=0 can be written as such, gives non-zero if odd
// 			res *= x;
// 		x = x*x;
// 		n = n>>1; // n/=2 can be written as such
// 	}
// 	return res;
// }

// computing pow(x, n) mod m in log time
// same as prev
// if m is prime, we can speed up using fermat little theorem as:
// in pow(x ,n), replace n by n % (m-1)
// int powerIterativeMod(int x, int n, int m) {
// 	a %= m;
// 	int res = 1;
// 	while (n>0) {
// 		if (n & 1)  // n%2!=0 can be written as such, gives non-zero if odd
// 			res *= x % m;
// 		x = x*x % m;
// 		n = n >> 1; // n/=2 can be written as such
// 	}
// 	return res;
// }

// variation of binary exponentiation in multiply a*b(mod m)
// a*b = 2 * a/2 * b, iff a > 0 and even
// 	  = 2* a-1/2 * b + b, iff odd


// perfect number - if sum of proper divisors is equal to number itself
// proper divisor is excluding number itself
// bool isPerfect(int n) {
// 	int sum =   1;
// 	for (int i = 2; i*i <= n; ++i) {
// 		if (n % i == 0) {
// 			if (i*i != n) {
// 				sum += i + n/i;
// 			}
// 			else
// 				sum += i;
// 		}
// 	}
// 	if (sum == n && n!= 1)
// 		return true;
// 	return false;
// }

//   Armstrong number
// abc.. = pow(a,n) + pow(b,n) + pow(c,n)+...
// ex 153 = 1*1*1 + 5*5*5 + 3*3*3
// function to calculate order of a number
// int order (int x) {
// 	int n = 0;
// 	while (x) {
// 		n++;
// 		x /= 10;
// 	}
// 	return n;
// }
// bool isArmstrong (int num) {
// 	int n = order(num);
// 	int temp = num, sum = 0;
// 	while (temp) {
// 		int digit = temp % 10;
// 		sum += power(digit, n);
// 		temp /= 10;
// 	}
// 	return (sum == num)
// }


// Euler totient function
// phi (pow(p,x)) = pow(p,x) - no of ints not comprime with p or pow(p, x) - pow(p,x-1) or (p-1)(pow(p,x-1))
// This function is a multiplicative function
// that is, f(n, m) = f(n)*f(m) where (m, n) = 1
// divisor_count(pow(p, x)) = (x + 1), where p is prime
// by simple rearranging, we can get for any n > 1
// phi (n) = n* (p1 -1)/p1 * (p2 -1)/p2 * ...*(pk -1)/pk, where pi are the prime facors of n
int phi (int n) {
	int res = n;
	if (n == 1) return 1;
	for (int i = 2; i*i <= n; ++i) {
		if (n % i == 0) {
			res /= i;
			res *= (i - 1);

			while (n % i == 0)
				n /= i;
		}
		
	}
	if (n > 1) {
			res /= n;
			res *= (n-1);
		}
	return res;
}

 
int main()
{
	 // cout << count_digit(1238595739);
	// cout << isPalindrome(4567654);
	// cout << fact(5);
	// cout << countTrailingZeroes(125);
	// cout << gcd(4,6);
    // cout << lcm(4, 6);
	// (isPrime(1031)) ? cout << "Prime" : cout << "Composite";
	// printPrimeFactors(450);
	// printDivisors(96);
	// sieve(100);
	// cout << power(3,4);
	// cout << power(3, 4);
	// cout << powerIterative(4,5);

// O (log max(a, b))
	// int x, y, a = 35, b = 15;
	// int g = gcdExtended(a, b, x, y);
	// cout << "gcd: " << g << " ";
	// cout << x << " " << y;

	// for (int n = 2; n < 10000; ++n) {
	// 	if (isPerfect(n))
	// 		cout << n << " is a perfect number\n";
	// }

    // int x = 1, y = 0;
	// cout << gcdExFaster(161, 28, x, y) << " "<<x <<" "<< y;
	// return 0;

	// auto x = find_any_solution(2,5,1);
	// cout << x.first << " "<<x.second;

	// printPrimeFactors(12);

	// ETF
	for (int n = 1; n <= 10; ++n) {
		cout << "ETF(" << n << "): " << phi(n) << "\n"; 
	}
	// cout << phi(8);
}
