#include<iostream>

using namespace std;

long long Fibonacci(unsigned int n, long long fibNum1 = 0, long long fibNum2 = 1){
	if (n <= 0)
		return 0;
	if (n == 1)
		return fibNum2;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

long long FibonacciAnother( unsigned int n, long long fibNum1, long long fibNum2){
	if (n <= 0)
		return 0;
	if (n == 1)
		return fibNum2;
	return FibonacciAnother(n - 1, fibNum2, fibNum2 + fibNum1);
}

long long FibonacciLoop(unsigned int n, long long fibNum1, long long fibNum2){
	long long fibNum = 0;
	if (n <= 0)
		return 0;
	if (n == 1)
		return fibNum2;
	for (unsigned int i = 1; i < n; ++i){
		fibNum = fibNum1 + fibNum2;
		fibNum1 = fibNum2;
		fibNum2 = fibNum;
	}
	return fibNum;
}

int main(){
	int n;
	long long fibNum1 = 0, fibNum2 = 1;
	cin >> n;
	cout << Fibonacci(n) << endl;
	cout << FibonacciAnother(n, fibNum1, fibNum2) << endl;
	cout << FibonacciLoop(n, fibNum1, fibNum2) << endl;
	return 0;
}