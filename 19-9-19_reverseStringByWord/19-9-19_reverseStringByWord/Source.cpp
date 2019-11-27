#include <iostream>
#include <string>
using namespace std;

void allStar(char* pStr) {
	if (*pStr == '\0')
		return;
	if (*pStr != ' ' && *(pStr + 1) != ' ' && *(pStr + 1) != '\0')
		cout << *pStr << '*';
	else
		cout << *pStr;
	allStar(pStr + 1);
}

int main() {
	char* str = new char[17];
	string ss = "the cat returns.";
	for (int i = 0; i < 16; i++)
		str[i] = ss[i];
	str[16] = '\0';
	allStar(str);
	return 0;
}