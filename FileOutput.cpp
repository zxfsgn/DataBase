#include <fstream>
#include "Student.h"

using namespace std;

void printElement(ofstream& f,const int el) {
	f << el<< ' ' ;
}

void printElement(ofstream& f,const char* t)
{
	f << t<< ' ' ;
}

void printOneStudent(ofstream& f,Student& student) {
	f<< "\n|";
	printElement(f,student.id);
	printElement(f,student.name);
	printElement(f,student.surname);
	printElement(f,student.patronymic);
	printElement(f,student.group);
	for (auto grade : student.grades)
		f << grade;
	printElement(f,student.yearOfBirth);
};

void OutputToFile(const char* fileName, Student* students, int studentsAmount){
    ofstream f(fileName);
    for (int i{}; i < studentsAmount; ++i)
		printOneStudent(f,students[i]);
}