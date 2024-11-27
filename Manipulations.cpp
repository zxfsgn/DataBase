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
	for (int i = 0; i < studentsAmount; ++i) {
		students[i] = {};
	}
	studentsAmount = 0;
}

int getIndexById(Student* students, int studentsAmount, int id) {
	for (int i = 0; i < studentsAmount; ++i) {
		if (students[i].id == id) return i;
	}
	cout << "There's no student with this id";
	return -1;
}

void deleteOne(Student* students, int& studentsAmount) {
	cout << "Enter student's id: ";
	int id;
	cin >> id;
	int deletingIndex = getIndexById(students, studentsAmount--, id);
	for (int j = deletingIndex; j < studentsAmount; ++j) {
		students[j] = students[j+1];
	}
	students[studentsAmount] = {};
}

void createOne(Student* students, int& studentsAmount, int& currentId) {

	const int inputLength = 100;
	Student student{ currentId++ };
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
}

void changeOne(Student* students, int studentsAmount) {
	cout << "Enter student's id: ";
	int id;
	cin >> id;
	const int inputLength = 100;
	Student& student = students[getIndexById(students, studentsAmount, id)];
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
}