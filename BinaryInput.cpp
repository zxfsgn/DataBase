#include "Student.h"
#include "FileInput.h"
#include "Manipulations.h"

#include <fstream>
#include <iostream>

using namespace std;

void ConvertTextToBin(const char* textName,const char* binName) {
	ofstream fout(binName, ios::binary);
	ifstream fin(textName);

	//Проверить, создастся ли без иос::аут
	Student buf{};
	while (InitializeStudentFromText(fin, buf)) {
		fout.write(reinterpret_cast<char*>(&buf)+4, sizeof(buf)-4);
	}
	fin.close();
	fout.close();
}

void GetFromBinary(const char* binName, Student* students, int& studentsAmount, int& currentId) {
	ifstream fin(binName, ios::binary);
	if (!fin) {
		cerr << "Файл не читается";//в функцию
		return;
	}
	Student buf{};
	DeleteAll(students, studentsAmount);
	while (fin.read(reinterpret_cast<char*>(&buf) + 4, sizeof(buf) - 4)) {
		buf.id = currentId++;
		students[studentsAmount++] = buf;
	}
	fin.close();
}