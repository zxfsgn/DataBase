#include "InputKeyboard.h"
#include "Manipulations.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Student* InputFromKeyboard(Student* students, int& studentsAmount, int& currentId) {
	bool deleting;
	cout << "¬ы уверены, что хотите удалить все записи ? \n(1 - да, 0 - нет)\n";
	cin >> deleting;
	if (!deleting) return students;
	DeleteAll(students, studentsAmount);
	studentsAmount = 0;
	while (true) {
		createOne(students, studentsAmount, currentId);
		cout << "Finish (y/n): ";
		char answer{};
		cin >> answer;

		if (answer == 'Y' or answer == 'y') break;
	}

	return students;
}