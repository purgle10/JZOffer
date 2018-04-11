#include<iostream>
#include<vector>
#include<string>

using namespace std;

int rowM = 0;
int colM = 0;

bool check(vector<char> strM, int row, int col, string str, int index, vector<bool> useFlag){
	if (row < 0 || row > rowM - 1 || col < 0 || col > colM - 1 || useFlag[row*colM+col])
		return false;
	if (index == str.length()) //must have a sentence return true
		return true;
	useFlag[row*col + col] = true;
	if (str[index] != strM[row*colM + col]) //colM instead of col
		return false;

	bool isTrue = check(strM, row - 1, col, str, index + 1, useFlag) || check(strM, row + 1, col, str, index + 1, useFlag) || check(strM, row, col - 1, str, index + 1, useFlag) || \
		check(strM, row, col + 1, str, index + 1, useFlag);
	if (!isTrue){
		--index;
		useFlag[row*col + col] = false;
	}
	return isTrue;
}

int main(){
	//int row, col;
	vector<char> strMatrix;
	cin >> rowM >> colM;
	for (int i = 0; i < rowM*colM; ++i){
		char input;
		cin >> input;
		strMatrix.push_back(input);
	}
	string str;
	cin >> str;

	vector<bool> useFlag(rowM*colM);
	bool exist = false;
	for (int i = 0; i < rowM; ++i){
		for (int j = 0; j < colM; ++j){
			if (check(strMatrix, i, j, str, 0, useFlag)){
				exist = true;
				cout << "True" << endl;
				break;
			}
		}
	}
	if (!exist)
		cout << "False" << endl;
	return 0;
}