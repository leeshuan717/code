#include<iostream>
using namespace std;
long long  num1, num2;
long long  fib(int n) {
	long long  f1 = 0;
	long long  f2 = 1;
	long long  f3 = 1;
	for (int i = 0; i < n; i++) {
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main() {
	int a,b;
	
	for (int i = 0; i < 92; i++) {
		cout << i+1 << " " << fib(i) << endl;
	}
	cout << "fib中選第一個數:";
	cin >> a;
	num1 = fib(a-1);
	cout << "第" << a << "個:" << num1<<endl;

	cout << "fib中選第一個數:";
	cin >> b;
	num2 = fib(b-1);
	cout << "第" << b << "個:" << num2 << endl;
	unsigned long long sum;
	sum = num1 + num2;
	cout << "相加結果為:" << sum;
}
