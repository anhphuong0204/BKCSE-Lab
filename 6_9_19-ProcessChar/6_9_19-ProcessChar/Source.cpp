#include <iostream>
#include <string>;
using namespace std;

char* str_str(char* s1, char* s2) {
	// s1: con
	// s2: me
	int i = 0;
	char* s;
	while (s2[i] != '\0') {
		int j = 0;
		if (s1[0] == s2[i]) {
			bool check = true;
			while (s1[j] != '\0') {
				if (s1[j] != s2[i + j])
					check = false;
				j++;
			}
			if (check == true)
				break;
		}
		i++;
	}
	s = &s2[i];
	return s;
}

int main() {
	char* s1 = new char[4];
	char* s2 = new char[15];
	string str1 = "abc";
	string str2 = "222123w24abc23";

	for (int i = 0; i < 4; i++) {
		s1[i] = str1[i];
	}
	s1[3] = '\0';
	
	for (int i = 0; i < 15; i++) {
		s2[i] = str2[i];
	}
	s2[14] = '\0';

	cout << *str_str(s1, s2) << endl;
	cout << s2[3];
	return 0;

}
