#include "Student.h"
#include "Manipulations.h"
//#include "InputChecks.h"

#include <fstream>
#include <iostream>

using namespace std;

bool InitializeStudentFromText(ifstream& f, Student& student) {
	f >> student.name >> student.surname >> student.patronymic >> student.group;
	for (size_t j{}; j < 6; ++j)
		f >> student.grades[j];
	f >> student.yearOfBirth;
	return static_cast<bool>(f);
}

bool createOne(ifstream& f, Student* students, int& studentsAmount, int& currentId) {
	Student student;
	if (!InitializeStudentFromText(f, student))
		return false;
	student.id = currentId++;
	students[studentsAmount++] = student;
	return true;
}
//Переопределить все операторы ввода/вывода в классах
void InputFromTFile(const char* fileName, Student* students, int& studentsAmount, int& currentId) {
	DeleteAll(students, studentsAmount);
	ifstream f(fileName);
	if (!f) {
		cerr << "Файл не читается";
		return;
	}
	while (createOne(f, students, studentsAmount, currentId));
	f.close();
}