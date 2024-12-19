#include "InputKeyboard.h"
#include "Manipulations.h"
//#include "InputChecks.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void InputFromKeyboard(Student* students, int& studentsAmount, int& currentId) {
	DeleteAll(students, studentsAmount);
	while (true) {
		createOne(students, studentsAmount, currentId);
		cout << "Finish (y/n): ";
		char answer{};
		cin >> answer;
		if (answer == 'Y' or answer == 'y') break;
	}
}