#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k) {
	//Write your code here.
	deque<int> KMax;
	deque<int> subArr;
	for (int i = 0; i < n - k + 1; i++) {
		subArr.push_back(i);
	}
	while (subArr.size() > 1) {
		if (arr[*subArr.begin()] > arr[*(subArr.end() - 1)]) {
			subArr.pop_back();
		}
		else {
			subArr.pop_front();
		}
	}
	//KMax.push_back(subArr[0]);
	cout << arr[*subArr.begin()];
}

int main() {
	int n, k;
	cin >> n >> k;
	int i;
	int * arr = new int[n];
	for (i = 0; i < n; i++)
		cin >> arr[i];
	printKMax(arr, n, k);
	delete[] arr;

	return 0;
}