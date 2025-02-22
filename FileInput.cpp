#include "Student.h"
#include "Manipulations.h"
#include "FileOutput.h"

#include <fstream>
#include <iostream>

using namespace std;

bool InitializeStudentFromText(wifstream &f, Student &student)
{
  f >> student.name >> student.surname >> student.patronymic >> student.group;
  for (size_t j{}; j < 6; ++j)
    f >> student.grades[j];
  f >> student.yearOfBirth;
  return static_cast<bool>(f);
}

bool createOne(wifstream &f, Student *students, int &studentsAmount, int &currentId)
{
  Student student;
  if (!InitializeStudentFromText(f, student))
    return false;
  student.id = currentId++;
  students[studentsAmount++] = student;
  return true;
}

void InputFromTFile(const char *fileName, Student *students, int &studentsAmount, int &currentId)
{
  DeleteAll(students, studentsAmount);
  wifstream f(fileName);
  if (!fileCheck(f, L"Файл не может быть открыт\n"))
    return;
  while (createOne(f, students, studentsAmount, currentId))
    ;
  wcout << L"\nДАННЫЕ ПОЛУЧЕНЫ\n";
  f.close();
}