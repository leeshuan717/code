#include<iostream>
using namespace std;

void swap(int *a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void factors(int n) {
	for (int i = 2; i <= n; i++) {
		int s = 0;
		while (n % i == 0) {
			s++;
			n /= i;
		}
		if (s > 1) {
			cout << i << "^" << s;
			if (n != 1) cout << "*";
		}
		if (s == 1) {
			cout << i;
			if (n != 1) cout << "*";
		}
	}
}
//calculate
void calculate(int a,int b) {
	int temp;
	//cin >> a >> b;
	factors(a);
	cout << ", ";
	factors(b);
	cout << ", ";
	if (a < b) swap(&a, &b);
	while (b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	cout << a;
	cout << ",";
	for (int i = 2; i < a; i++) {
		if (a % i == 0) {
			cout << "N";
			return ;
		}
	}
	cout << "Y";
}
int main() {
	int i = 0;
	int num[8] = { 0 };
	for (int j = 0; j < 7; j += 2) {
		cin >> num[j] >> num[j + 1];
	}
	for (int j = 0; j < 7; j += 2) {
		calculate(num[j], num[j + 1]);
		cout << endl;
	}
}
