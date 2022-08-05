#include <bits/stdc++.h>
using namespace std;


// C++ implementation of the approach
#include <cmath>
#include <iostream>
using namespace std;

#define ull unsigned long long int

// Function to return the binary
// equivalent of decimal value N
int d2B(int N)
{

	// To store the binary number
	ull B_Number = 0;
	int cnt = 0;
	while (N != 0) {
		int rem = N % 2;
		ull c = pow(10, cnt);
		B_Number += rem * c;
		N /= 2;

		// Count used to store exponent value
		cnt++;
	}

	return B_Number;
}

// Driver code
int main()
{

	int x = 187;
  //int x1 = 16;
	int k = 4;
	cout << d2B(x)<<endl;
	//cout << d2B(N | (1<<(k-1)));
    //cout << d2B(N & ~(1<<(k-1)));
    //cout << d2B(x^(1<<(k-1)));
    //cout << floor(log2(x)+1);
    //cout << d2B(x1 & ~(x1-1));
    cout << d2B(x>>k);
	return 0;
}