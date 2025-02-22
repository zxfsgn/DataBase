#include "Student.h"

#include <fstream>
#include <iostream>

using namespace std;

bool fileCheck(wofstream &f, const wchar_t *massage)
{
  if (!f)
  {
    wcerr << massage;
    return false;
  }
  return true;
}

bool fileCheck(wifstream &f, const wchar_t *massage)
{
  if (!f)
  {
    wcerr << massage;
    return false;
  }
  return true;
}

void printElement(wofstream &f, const int el)
{
  f << el << ' ';
}

void printElement(wofstream &f, const wchar_t *t)
{
  f << t << ' ';
}

void printOneStudent(wofstream &f, Student &student)
{
  printElement(f, student.name);
  printElement(f, student.surname);
  printElement(f, student.patronymic);
  printElement(f, student.group);
  for (auto grade : student.grades)
    printElement(f, grade);
  f << student.yearOfBirth;
};

void OutputToFile(const char *fileName, Student *students, int studentsAmount)
{
  wofstream f(fileName);
  if (!fileCheck(f, L"Файл не может быть создан\n"))
    return;
  if (studentsAmount != 0)
    printOneStudent(f, students[0]);
  for (int i = 1; i < studentsAmount; ++i)
  {
    f << "\n";
    printOneStudent(f, students[i]);
  }
  wcout << L"\nВсё выведено успешно\n";
  f.close();
}