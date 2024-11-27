#include "OutputScreen.h"
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;

struct Width {
	int id;
	int name;
	int group;
	int grades;
	int birthYear;
	int total = id + name * 3 + group + grades + birthYear + 8;
};

void printBorder(const int amount) {
	cout << '\n';
	for (int i = 0; i < amount; ++i) cout << '-';
}

void printElement(const int el, const int width) {
	cout << left << setw(width) << el << '|';
}

void printElement(const char* t, const int width)
{
	const char separator = '|';
	cout << left << setw(width) << t << separator;
}
//������� ��������
void printTitle(Width width) {
	char titles[][20] = {"Id", "Name" ,"Surname","Patronymic","Group","Grades", "BYear" };
	cout << "\n|";
	int i = 0;
	printElement(titles[i++], width.id);
	while (i < 4) printElement(titles[i++], width.name);
	printElement(titles[i++], width.group);
	printElement(titles[i++], width.grades);
	printElement(titles[i++], width.birthYear);
}

void printOneStudent(Student student, const Width width) {
	cout << "\n|";
	printElement(student.id, width.id);
	printElement(student.name, width.name);
	printElement(student.surname, width.name);
	printElement(student.patronymic, width.name);
	printElement(student.group, width.group);
	for (auto grade : student.grades)
		cout << left << setw(2) << grade;
	cout << '|';
	printElement(student.yearOfBirth, width.birthYear);
};

void OutputToTheScreen(Student* students, int studentsAmount) {
	const Width width{3, 16, 10, 12, 5 };
	printBorder(width.total);
	printTitle(width);
	printBorder(width.total);
	for (int i{}; i < studentsAmount; ++i)
		printOneStudent(students[i], width);
	printBorder(width.total);
	cout << '\n';
}