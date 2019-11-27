#include <iostream>
#include <cstring>
#include <fstream>

int lengthString(char* initialString) {
	int c = 0;
	while (*initialString != '\0') {
		c++;
		initialString++;
	}
	return c;
}

void reverseString(char* initialString) {
	//static int len = lengthString(initialString) - 1;

	if (*initialString == '\0') {
		return;
	}
	else {
		reverseString(initialString + 1);
		std::cout << *initialString;
	}
}

int main() {
	char* s = new char[10];
	std::string ss = "123456789";
	for (int i = 0; i < 10; i++)
		s[i] = ss[i];
	s[10] = '\0';
	reverseString(s);
	return 0;

}