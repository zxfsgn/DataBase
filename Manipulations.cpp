#include "Manipulations.h"
#include "InputChecks.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::cin;
using std::cout;
using std::setw;
using std::numeric_limits;
using std::streamsize;

void FixStreamState() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void DeleteAll(Student* students, int& studentsAmount) {
	if (studentsAmount == 0) return;
	bool deleting;
	cout << "Удалить все записи ? \n(1 - да, 0 - нет)\n";
	cin >> deleting;
	if (!deleting) return;
	for (int i = 0; i < studentsAmount; ++i) {
		students[i] = {};
	}
	studentsAmount = 0;
}

int getIndexById(Student* students, int studentsAmount, int id) {
	for (int i = 0; i < studentsAmount; ++i) {
		if (students[i].id == id) return i;
	}
	cout << "There's no student with this id\n";
	return -1;
}

void deleteOne(Student* students, int& studentsAmount) {
	cout << "Введите номер студента: ";
	int index;
	cin >> index;
	if (IndexCheck(index, studentsAmount)) {
		for (int j = index - 1; j < studentsAmount; ++j) {
			students[j] = students[j + 1];
		}
		students[--studentsAmount] = {};
		cout << "Удаление прошло успешно\n";
	}
	else
		cout << "Удаление отменено\n";
}

void createOne(Student* students, int& studentsAmount, int& currentId) {

	const int inputLength = 100;
	Student student{ currentId++ };
	FixStreamState();
	cout << "Enter student's group: ";
	cin.getline(student.group, inputLength, '\n');//no check
	
	cout << "Enter the student's surname: ";
	cin.getline(student.surname, inputLength, '\n');//check for symbols in ABC
	cout << "Enter the student's name: ";			//and autoformat to Abc
	cin.getline(student.name, inputLength, '\n');	//no spaces
	cout << "Enter the student's patronymic: ";
	cin.getline(student.patronymic, inputLength, '\n');

	cout << "Enter student's year of birth: ";
	student.yearOfBirth = BirthCheck(2012, 1900);//no spaces
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter student's grades: ";//no spaces
	for (size_t j{}; j < 6; ++j) {		//range
		cin >> student.grades[j];
	}

	students[studentsAmount++] = student;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Студент добавлен\n";
}

void changeOne(Student* students, int studentsAmount) {
	cout << "Введите номер студента: ";
	int number;
	cin >> number;
	const int inputLength = 100;
	if (IndexCheck(number, studentsAmount)) {
		Student& student = students[number - 1];
		FixStreamState();
		cout << "Enter student's group: ";
		cin.getline(student.group, inputLength, '\n');

		cout << "Enter the student's surname: ";
		cin.getline(student.surname, inputLength, '\n');
		cout << "Enter the student's name: ";
		cin.getline(student.name, inputLength, '\n');
		cout << "Enter the student's patronymic: ";
		cin.getline(student.patronymic, inputLength, '\n');

		cout << "Enter student's year of birth: ";
		student.yearOfBirth = BirthCheck(2012, 1900);

		cout << "Enter student's grades: ";
		for (size_t j{}; j < 6; ++j) {
			cin >> student.grades[j];
		}

		students[studentsAmount++] = student;
		FixStreamState();
		cout << "Студент изменён\n";
	}
	else {
		cout << "Изменение отменено\n";
	}
}