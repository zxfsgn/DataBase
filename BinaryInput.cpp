#include <fstream>
#include "Student.h"
#include <cmath>

using namespace std;

unsigned stoi(unsigned n, char* str) {
	if (n == 0) return 0;
	return stoi(n - 1, str + 1) + (static_cast<int>(*str) - 48) * pow(10, n - 1);
}

int getSizeStr(char* str){
    int i = -1;
    while(str[++i]!='\0');
    return i;
}

void createOneBin(ifstream& f,Student* students, int& studentsAmount, int& currentId) {
    char buff[50]{};
	Student student{ currentId++ };
	f.getline(student.surname,50,' ');
    f.getline(student.name,50,' ');
    f.getline(student.patronymic,50,' ');
    f.getline(student.group,50,' ');
	
    for (size_t j{}; j < 6; ++j) {
		f.getline(buff,50,' ');
        student.grades[j] = stoi(getSizeStr(buff) , buff);
	}
    f.getline(buff,50);
    student.yearOfBirth = stoi(getSizeStr(buff)-1, buff);
	students[studentsAmount++] = student;
}

void InputFromBin(const char* fileName, Student* students, int& studentsAmount, int& currentId){
    ifstream f(fileName, ios::binary);
    while(!f.eof()){
        createOneBin(f,students,studentsAmount, currentId);
    }
}