#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
using namespace std;

struct Grade {
	float quiz_mark, lab_mark, assignment_mark, exam_mark, sum;
};

struct Student {
	int id;
	string name;
	Grade mark;
};

void print_result(Student st) {
	float sumGrade;
	sumGrade = st.mark.quiz_mark * 0.1f + st.mark.lab_mark * 0.15f + st.mark.assignment_mark * 0.25f + st.mark.exam_mark * 0.5f;
	if (st.mark.exam_mark < 3)
		st.mark.sum = st.mark.exam_mark;
	else if (static_cast<int>(st.mark.exam_mark) == 13)
		st.mark.sum = 0;
	else
		st.mark.sum = sumGrade;

	cout << st.id << endl;
	cout << st.mark.sum;
}

int main() {
	Student st;

	st.id = 123;
	st.mark.quiz_mark = 2.f;
	st.mark.lab_mark = 2.f;
	st.mark.assignment_mark = 2.f;
	st.mark.exam_mark = 13.f;
	print_result(st);

	system("pause");
	return 0;
}