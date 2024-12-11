#include <iostream>
#include <cmath>
#include "Student.h"
#include "Manipulations.h"
#include "OutputScreen.h"
#include "InputKeyboard.h"
#include "InputChecks.h"
#include "Request.h"
#include "Sort.h"
#include "FileOutput.h"
#include "FileInput.h"
#include "BinaryInput.h"

using std::cout;
using std::endl;
//����� ���������� ��� �������� ��������

const char FILE_NAME[] = "Students.txt";
const char BIN_NAME[] = "Students.txt";

int main() {
	setlocale(LC_ALL, "Russian");

	int studentsAmount{ };
	int currentId{};

	Student* students = new Student[100]{ };
	size_t max_length{};

	int command{};

	do {
		PrintMenu();
		command = GetCorrectValue();
		switch (command) {
		case 1:InputFromKeyboard(students, studentsAmount, currentId); break;
		case 2:InputFromBin(FILE_NAME, students,studentsAmount,currentId);break;
		case 3:InputFromBin(BIN_NAME, students,studentsAmount,currentId);break;
		case 4:OutputToTheScreen(students, studentsAmount); break;
		case 5: OutputToFile(FILE_NAME,students,studentsAmount);break;
		case 6: request(students, studentsAmount); break;
		case 9: createOne(students, studentsAmount, currentId); break;
		case 10: changeOne(students, studentsAmount); break;
		case 11: deleteOne(students, studentsAmount); break;
		case 12: sortShell(students,0, studentsAmount-1);
		case 0: cout << "BB" << endl; break;
		default: cout << "illegal command\n";
		}

	} while (command);
}

void PrintMenu() {
	cout << "1 - input from keyboard" << endl;
	cout << "2 - input from a text flie" << endl;
	cout << "3 - input from a binary flie" << endl;
	cout << "4 - output to the screen" << endl;
	cout << "5 - output to the flie" << endl;
	cout << "6 - printout on request" << endl;
	//cout << "7 - transfer to a text file" << endl;
	//cout << "8 - transfer text file to binary" << endl;
	cout << "9 - add student" << endl;
	cout << "10 - change student" << endl;
	cout << "11 - delete student" << endl;
	cout << "12 - sort" << endl;
	cout << "0 - exit" << endl;
}


