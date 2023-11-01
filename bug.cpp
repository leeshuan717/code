#include <iostream>

using namespace std;

void main() {
	int n;
	cin >> n;
	int fn = n * n + n + 41;
	for (int i = 2; i < fn; i++) {
		if (fn % i == 0) {
			cout<< "n";
			return;
		}
	}
	cout << "y";
}
