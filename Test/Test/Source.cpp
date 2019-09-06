#include <iostream>
using namespace std;

int main() {
	int decNum;
	cin >> decNum;
	char hexNum[20];
	int countNum = 0;
	while (decNum != 0) {
		int q = decNum % 16;
		if (q > 9) {
			switch (q) {
			case 10: {
				hexNum[countNum] = 'a';
				break;
			}
			case 11: {
				hexNum[countNum] = 'b';
				break;
			}
			case 12: {
				hexNum[countNum] = 'c';
				break;
			}
			case 13: {
				hexNum[countNum] = 'd';
				break;
			}
			case 14: {
				hexNum[countNum] = 'e';
				break;
			}
			case 15: {
				hexNum[countNum] = 'f';
				break;
			}
			}
		}
		else {
			hexNum[countNum] = static_cast<char>(q + 48);
		}
		decNum = decNum / 16;
		countNum++;
	}
	cout << countNum << endl;
	cout << "0x";
	for (int i = countNum - 1; i >= 0; i--) {
		cout << hexNum[i];
	}

	return 0;
}