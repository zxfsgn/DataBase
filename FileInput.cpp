#include <fstream>
#include "Student.h"

using namespace std;

void createOne(ifstream& f,Student* students, int& studentsAmount, int& currentId) {

	Student student{ currentId++ };
	f>>student.surname;
    f>>student.name;
    f>>student.patronymic;
    f>>student.group;
	
    for (size_t j{}; j < 6; ++j) {
		f >> student.grades[j];
	}
    f>>student.yearOfBirth ;

	students[studentsAmount++] = student;
}

void InputFromFile(const char* fileName, Student* students, int& studentsAmount, int& currentId){
    ifstream f(fileName);
    while(!f.eof()){
        createOne(f,students,studentsAmount, currentId);
    }
}