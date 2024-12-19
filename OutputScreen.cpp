#include "OutputScreen.h"
#include "Widths.h"

#include <iostream>
#include <iomanip>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::left;
using namespace std;

int strLenght(const char* str) {
	int i = -1;
	while (str[++i] != '\0');
	return i;
}

void addSideSpaces(int n) {
	for (int i = 0; i < n; ++i)
		cout << ' ';
}

void printBorder(const int amount) {
	cout << '\n';
	for (int i = 0; i < amount; ++i) cout << '-';
}

void printElement(const int el, const int width) {
	if (el == -1)
		cout << left << setw(width) << ' ' << '|';
	else
		cout << left << setw(width) << el << '|';
}

const char* printElement(const char* t, const int width, bool centerAllign = false) {
	const char separator = '|';
	int strLen = strLenght(t);
	int shift = 0;
	int j = 0;
	if (centerAllign && strLen < width) {
		j = (width - strLen) / 2;
		addSideSpaces(j);
	}
	while (shift < width and shift < strLen) {
		cout << t[shift++];
	}
	j += shift;
	addSideSpaces(width - j);
	cout << separator;

	return t + shift;
}

void printTitle(Widths width) {
	char titles[][20] = { "¹", "Name" ,"Surname","Patronymic","Group","Grades", "BYear" };
	cout << "\n|";
	int i = 0;
	printElement(titles[i++], width.id, true);
	while (i < 4) printElement(titles[i++], width.name, true);
	printElement(titles[i++], width.group, true);
	printElement(titles[i++], width.grades, true);
	printElement(titles[i++], width.birthYear, true);
}

void printOneStudent(int index, Student& student, const Widths width) {
	cout << "\n|";
	Student buffer{ -1 };
	bool isExcess = false;
	printElement(index + 1, width.id);
	strcpy(buffer.name, printElement(student.name, width.name));
	strcpy(buffer.surname, printElement(student.surname, width.name));
	strcpy(buffer.patronymic, printElement(student.patronymic, width.name));
	strcpy(buffer.group, printElement(student.group, width.group, true));
	for (auto grade : student.grades)
		cout << left << setw(2) << (grade != 0 ? static_cast<char>(grade + 48) : ' ');
	cout << '|';
	printElement(student.yearOfBirth, width.birthYear);
	buffer.yearOfBirth = -1;
	if (strcmp(buffer.name, "") || strcmp(buffer.surname, "")
		|| strcmp(buffer.patronymic, "") || strcmp(buffer.group, ""))
		printOneStudent(-2, buffer, width);
};

void OutputToTheScreen(Student* students, int studentsAmount) {
	const Widths width{ 3, 16, 10, 12, 5 };
	printBorder(width.total);
	printTitle(width);
	printBorder(width.total);
	for (int i{}; i < studentsAmount; ++i)
		printOneStudent(i, students[i], width);
	printBorder(width.total);
	cout << '\n';
}