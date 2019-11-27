#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define MAXCHAR 100

//You can write some function for this exercise
bool isNum(char n) {
	int num = static_cast<int>(n);
	for (int i = 48; i <= 57; i++) {
		if (num == i) {
			return 1;
		}
	}
	return 0;
}

bool isChar(char n) {
	if (n == '+')
		return 1;
	else if (n == '-')
		return 1;
	else if (n == '*')
		return 1;
	else if (n == '/')
		return 1;
	return 0;
}

int cal(int a, int b, char n) {
	switch (n) {
	case '+':
		return a + b;
		break;
	case '-':
		return b - a;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return b / a;
		break;
	}
}

int CalculatePostfix(char postfix[])
{
	stack<int> s;
	int len = 0;
	for (int i = 0; i < MAXCHAR; i++) {
		if (postfix[i] == '\0')
			break;
		len++;
	}
	for (int i = 0; i < len; i++) {
		if (isNum(postfix[i])) {
			s.push(static_cast<int>(postfix[i]) - 48);
		}
		else if (isChar(postfix[i])) {
			int a = s.top();
			s.pop();
			int b = s.top();
			s.pop();
			s.push(cal(a, b, postfix[i]));
		}
	}
	if (len == 0)
		return 0;
	return s.top();
}

int main(int argc, char* argv[]) {
	char postfix[MAXCHAR];
	string ss = "56*82/+2-";
	for (int i = 0; i < ss.length(); i++) {
		postfix[i] = ss[i];
	}
	postfix[ss.length()] = '\0';
	cout << CalculatePostfix(postfix) << endl;
	return 0;
}