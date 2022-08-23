#include <iostream>
using namespace std;

void toh(int n, int src, int helper, int dest, int &count) {
	count++;
	if (n == 0) {
		return;
	}
	toh(n- 1, src, dest, helper, count);
	cout << "Move " << src << " to " << dest << "\n";
	toh(n - 1, helper, src, dest, count);
}
int main() {
	int n = 3;
	int count = 0;
	toh(3, 1, 2, 3, count);

	cout << "No. of operations done: " << count;
	return 0;
}