#include "Manipulations.h"
#include "InputChecks.h"
#include <iostream>
#include <iomanip>
#include <limits>

using std::numeric_limits;
using std::setw;
using std::streamsize;
using std::wcin;
using std::wcout;

void FixStreamState()
{
  wcin.clear();
  wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
}

void getName(wchar_t *str, int inputLength)
{
  do
    wcin.getline(str, inputLength);
  while (!isStringValid(str));
}

int getStudentNum()
{
  wcout << L"Введите номер студента: ";
  int number;
  wcin >> number;
  return number;
}

void DeleteAll(Student *students, int &studentsAmount)
{
  if (studentsAmount == 0)
    return;
  bool deleting;
  wcout << L"Удалить все записи? \n(1 - да, 0 - нет)\n";
  wcin >> deleting;
  if (!deleting)
    return;
  for (int i = 0; i < studentsAmount; ++i)
  {
    students[i] = {};
  }
  studentsAmount = 0;
}

void InitializeStudent(Student &student)
{ // add autoformat for strings
  const int inputLength = 100;
  wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
  wcout << L"Введите группу: ";
  wcin.getline(student.group, inputLength);
  wcout << L"Введите фамилию: ";
  getName(student.surname, inputLength);
  wcout << L"Имя: ";
  getName(student.name, inputLength);
  wcout << L"Отчество: ";
  getName(student.patronymic, inputLength);
  wcout << L"Год рождения: ";
  student.yearOfBirth = BirthCheck(2012, 1900);
  wcin.ignore(numeric_limits<streamsize>::max(), L'\n');

  wcout << L"Введите 6 оценок: ";
  for (size_t j{}; j < 6; ++j)
    student.grades[j] = GradeCheck(j);
  wcin.ignore(numeric_limits<streamsize>::max(), L'\n');
}

void deleteOne(Student *students, int &studentsAmount)
{
  int number = getStudentNum();
  if (IndexCheck(number, studentsAmount) && areYouSure())
  {
    for (int j = number - 1; j < studentsAmount; ++j)
    {
      students[j] = students[j + 1];
    }
    students[--studentsAmount] = {};
    wcout << L"Зафикисровано удаление студента\n";
  }
  else
    wcout << L"Удаление студента не случилось\n";
}

void createOne(Student *students, int &studentsAmount, int &currentId)
{
  Student student{currentId++};
  InitializeStudent(student);
  students[studentsAmount++] = student;
  wcout << L"Создание студента успешно завершено\n";
}

void changeOne(Student *students, int studentsAmount)
{
  int number = getStudentNum();
  if (IndexCheck(number, studentsAmount))
  {
    Student &student = students[number - 1];
    InitializeStudent(student);
    wcout << L"Сущность студента изменена\n";
  }
  else
  {
    wcout << L"Нет удалось изменить сущность студента\n";
  }
}