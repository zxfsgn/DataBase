#include "Request.h"
#include <iostream>

using std::cout;

void request(Student* students, const int studentsAmount) {
	for (int i = 0; i < studentsAmount; ++i) {
		bool fl = true;
		int fourCounter = 0;
		for (auto grade : students[i].grades) {
			if (grade < 4 or grade == 4 and ++fourCounter > 2) {
				fl = false;
				break;
			}
		}
		if (fl) cout << students[i].surname << ' ' << students[i].group << '\n';
	}
}