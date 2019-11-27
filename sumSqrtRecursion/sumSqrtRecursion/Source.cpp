#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;

double square_sum(int x) {
	if (x == 1)
		return static_cast<double>(x);
	else
		return sqrt(static_cast<double>(x) + square_sum(x - 1));
}

int main() {
	cout << square_sum(3) << endl;
	return 0;
}