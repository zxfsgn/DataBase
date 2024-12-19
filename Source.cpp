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

const char TFILE_NAME[] = "Students.txt";
const char BIN_NAME[] = "Students.bin";
//const char TEXT_NAME[] = "text.txt";

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
		case 2:InputFromTFile(TFILE_NAME, students, studentsAmount, currentId); break;
		case 3:GetFromBinary(BIN_NAME, students, studentsAmount, currentId); break;
		case 4:OutputToTheScreen(students, studentsAmount); break;
		case 5: OutputToFile(TFILE_NAME, students, studentsAmount); break;
		case 6: request(students, studentsAmount); break;
		case 7: ConvertTextToBin(TFILE_NAME, BIN_NAME); break;
		case 8: createOne(students, studentsAmount, currentId); break;
		case 9: changeOne(students, studentsAmount); break;
		case 10: deleteOne(students, studentsAmount); break;
		case 11: sortShell(students, 0, studentsAmount - 1); break;
		case 0: cout << "BB" << endl; break;
		default: cout << "illegal command\n";
		}

	} while (command);
}

void PrintMenu() {
	//cycle of consts
	cout << "1 - input from keyboard" << endl;
	cout << "2 - input from a text flie" << endl;
	cout << "3 - input from a binary flie" << endl;
	cout << "4 - output to the screen" << endl;
	cout << "5 - output to the flie" << endl;
	cout << "6 - printout on request" << endl;
	cout << "7 - transfer text file to binary" << endl;
	cout << "8 - add student" << endl;
	cout << "9 - change student" << endl;
	cout << "10 - delete student" << endl;
	cout << "11 - sort" << endl;
	cout << "0 - exit" << endl;
}


