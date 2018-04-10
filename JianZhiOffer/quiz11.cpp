#include<iostream>
#include<vector>

using namespace std;

int rotateArrayMinValue(vector<int> arr){
	int size = arr.size();
	int left = 0;
	int right = size - 1;
	int index = left;
	if (arr[left] < arr[right])
		return arr[left];
	while (left<right){
		index = (right + left) / 2;
		if (arr[index]>arr[left])
			left = index + 1;
		else if (arr[index] < arr[right])
			right = index - 1;
	}
	return arr[index];
}

int main(){
	int input;
	int N, count = 0;
	cin >> N;
	vector<int> arr;
	while (count != N){
		cin >> input;
		arr.push_back(input);
		count++;
	}

	cout << rotateArrayMinValue(arr) << endl;
	return 0;
}