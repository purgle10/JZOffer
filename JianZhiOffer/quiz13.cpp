#include<iostream>
#include<vector>

using namespace std;

int rowMatrix = 0;
int colMatrix = 0;
//int mCount = 0;

int getDigitNumber(int num){
	int n = 0;
	while (num){
		n += num % 10;
		num = num / 10;
	}
	return n;
}

bool check(vector<bool>useFlag, int row, int col, int threshold){
	if (row < 0 || row >= rowMatrix || col < 0 || col >= colMatrix || useFlag[row*colMatrix + col] || \
		getDigitNumber(row) + getDigitNumber(col) > threshold)
		return false;
	return true;
}

int movingCount(vector<bool> &useFlag, int row, int col, int threshold){//pay attention to the reference of useFlag
	int mCount = 0;
	if (check(useFlag, row, col, threshold)){
		useFlag[row*colMatrix + col] = true;
		mCount = 1 + movingCount(useFlag, row - 1, col, threshold) +\
			movingCount(useFlag, row + 1, col, threshold)+\
			movingCount(useFlag, row, col - 1, threshold)+\
			movingCount(useFlag, row, col + 1, threshold);
	}
	return mCount;
}

int main(){
	cin >> rowMatrix >> colMatrix;
	int threshold;
	cin >> threshold;

	if (rowMatrix <= 0 || colMatrix <= 0 || threshold < 0)
		return 0;

	vector<bool> useFlag(rowMatrix*colMatrix);
	int mCount = movingCount(useFlag, 0, 0, threshold);
	cout << mCount << endl;
	return 0;
}