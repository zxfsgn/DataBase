#include <fstream>
#include "Student.h"

using namespace std;

void printElement(ofstream& f, const int el) {
	f << el << ' ';
}

void printElement(ofstream& f, const char* t)
{
	f << t << ' ';
}

void printOneStudent(ofstream& f, Student& student) {
	printElement(f, student.name);
	printElement(f, student.surname);
	printElement(f, student.patronymic);
	printElement(f, student.group);
	for (auto grade : student.grades)
		printElement(f, grade);
	f << student.yearOfBirth;
};
//checking for existing
void OutputToFile(const char* fileName, Student* students, int studentsAmount) {
	ofstream f(fileName);
	if (studentsAmount != 0) printOneStudent(f, students[0]);
	for (int i = 1; i < studentsAmount; ++i) {
		f << "\n";
		printOneStudent(f, students[i]);
	}
	f.close();
}