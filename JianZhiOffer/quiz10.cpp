#include<iostream>

using namespace std;

long long Fibonacci(long long n){
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

long long FibonacciAnother( unsigned int n, long long fibNum = 1, long long fibNum1 = 0){
	if (n <= 0)
		return 0;
	if (n == 1)
		return fibNum;
	return FibonacciAnother(n-1, fibNum + fibNum1, fibNum);
}

long long FibonacciLoop(unsigned int n){
	long long fibNum1 = 0;
	long long fibNum2 = 1;
	long long fibNum = 0;
	if (n <= 0)
		return 0;
	if (n == 1)
		return fibNum2;
	for (int i = 1; i < n; ++i){
		fibNum = fibNum1 + fibNum2;
		fibNum1 = fibNum2;
		fibNum2 = fibNum;
		//fibNum2 = fibNum1 + fibNum2;
	}
	return fibNum;
}

int main(){
	int n;
	cin >> n;
	//cout << Fibonacci(n) << endl;
	cout << FibonacciAnother(n) << endl;
	cout << FibonacciLoop(n) << endl;
	return 0;
}