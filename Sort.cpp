#include "Sort.h"
#include "Student.h"
#include "Others.h"

#include <iostream>
#include <cwchar>

using namespace std;

enum class Column
{
  Name,
  Surname,
  Patronymic,
  Group,
  Grade1,
  Grade2,
  Grade3,
  Grade4,
  Grade5,
  Grade6,
  GradeSum,
  YearOfBirth
};

void swap(Student[], int, int);
bool fieldCompare(Column, Student *, int, int, bool (*)(int, int), bool (*)(const wchar_t *, const wchar_t *));
void sort(Student *, int, int, Column, bool);
// should output column in loop through array of consts also used in title
void sortShell(Student *students, int start, int end)
{
  wcout << L"Выберите критерий для сортировки:\n";
  wcout << L"1 - имя" << endl;
  wcout << L"2 - фамилия" << endl;
  wcout << L"3 - Отчество" << endl;
  wcout << L"4 - группа" << endl;
  wcout << L"5 - оценка 1" << endl;
  wcout << L"6 - оценка 2 " << endl;
  wcout << L"7 - оценка 3" << endl;
  wcout << L"8 - оценка 4" << endl;
  wcout << L"9 - оценка 5" << endl;
  wcout << L"10- оценка 6" << endl;
  wcout << L"11- сумма оценок" << endl;
  wcout << L"12- год рождения" << endl;
  int colNumber;
  wcin >> colNumber;
  wcout << L"0 - по возрастанию, 1 - по убыванию\n";
  bool isAscending;
  wcin >> isAscending;
  Column column = static_cast<Column>(--colNumber);
  sort(students, start, end, column, isAscending);
}

bool isGreater(const wchar_t *lStr, const wchar_t *rStr)
{
  if (wmemcmp(lStr, rStr, 100) > 0)
    return true;
  return false;
}

bool isSmaller(const wchar_t *lStr, const wchar_t *rStr)
{
  if (wmemcmp(lStr, rStr, 100) < 0)
    return true;
  return false;
}

bool isGreater(int lNum, int rNum)
{
  if (lNum > rNum)
    return true;
  return false;
}

bool isSmaller(int lNum, int rNum)
{
  if (lNum < rNum)
    return true;
  return false;
}

void sort(Student *students, int start, int end, Column column, bool isAscending)
{
  if (start >= end)
    return;
  bool (*compInt)(int, int);
  bool (*compStr)(const wchar_t *, const wchar_t *);
  if (isAscending)
  {
    compInt = isSmaller;
    compStr = isSmaller;
  }
  else
  {
    compInt = isGreater;
    compStr = isGreater;
  }
  int current{start};
  for (int i{start + 1}; i <= end; i++)
    if (fieldCompare(column, students, start, i, compInt, compStr))
      swap(students, ++current, i);
  swap(students, start, current);
  sort(students, start, current - 1, column, isAscending);
  sort(students, current + 1, end, column, isAscending);
}

void swap(Student students[], int first, int second)
{
  auto temp{students[first]};
  students[first] = students[second];
  students[second] = temp;
}

bool fieldCompare(Column column, Student *students, int k, int l, bool (*compInt)(int, int), bool (*compStr)(const wchar_t *, const wchar_t *))
{
  switch (column)
  {
  case Column::Name:
    return compStr(students[k].name, students[l].name);
    break;
  case Column::Surname:
    return compStr(students[k].surname, students[l].surname);
    break;
  case Column::Patronymic:
    return compStr(students[k].patronymic, students[l].patronymic);
    break;
  case Column::Group:
    return compStr(students[k].group, students[l].group);
    break;
  case Column::Grade1:
    return compInt(students[k].grades[0], students[l].grades[0]);
    break;
  case Column::Grade2:
    return compInt(students[k].grades[1], students[l].grades[1]);
    break;
  case Column::Grade3:
    return compInt(students[k].grades[2], students[l].grades[2]);
    break;
  case Column::Grade4:
    return compInt(students[k].grades[3], students[l].grades[3]);
    break;
  case Column::Grade5:
    return compInt(students[k].grades[4], students[l].grades[4]);
    break;
  case Column::Grade6:
    return compInt(students[k].grades[5], students[l].grades[5]);
    break;
  case Column::GradeSum:
    return ArrSum(students[k].grades, 6) < ArrSum(students[l].grades, 6);
    break;
  case Column::YearOfBirth:
    return compInt(students[k].yearOfBirth, students[l].yearOfBirth);
    break;
  }
  return true;
}
