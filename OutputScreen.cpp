#include "OutputScreen.h"
#include "Widths.h"

#include <iostream>
#include <iomanip>
#include <cwchar>

using std::endl;
using std::left;
using std::setw;
using std::wcin;
using std::wcout;
using namespace std;

int strLenght(const wchar_t *str)
{
  int i = -1;
  while (str[++i] != '\0')
    ;
  return i;
}

void addSideSpaces(int n)
{
  for (int i = 0; i < n; ++i)
    wcout << ' ';
}

void printBorder(const int amount)
{
  wcout << '\n';
  for (int i = 0; i < amount; ++i)
    wcout << '-';
}

void printElement(const int el, const int width)
{
  if (el == -1)
    wcout << left << setw(width) << ' ' << '|';
  else
    wcout << left << setw(width) << el << '|';
}

const wchar_t *printElement(const wchar_t *t, const int width, bool centerAllign = false)
{
  const wchar_t separator = '|';
  int strLen = strLenght(t);
  int shift = 0;
  int j = 0;
  if (centerAllign && strLen < width)
  {
    j = (width - strLen) / 2;
    addSideSpaces(j);
  }
  while (shift < width and shift < strLen)
  {
    wcout << t[shift++];
  }
  j += shift;
  addSideSpaces(width - j);
  wcout << separator;

  return t + shift;
}

void printTitle(Widths width)
{
  wchar_t titles[][20] = {L"№", L"Имя", L"Фамилия", L"Отчество", L"Группа", L"Оценки", L"Год"};
  wcout << "\n|";
  int i = 0;
  printElement(titles[i++], width.id, true);
  while (i < 4)
    printElement(titles[i++], width.name, true);
  printElement(titles[i++], width.group, true);
  printElement(titles[i++], width.grades, true);
  printElement(titles[i++], width.birthYear, true);
}

void printOneStudent(int index, Student &student, const Widths width)
{
  wcout << "\n|";
  Student buffer{-1};
  bool isExcess = false;
  printElement(index + 1, width.id);
  wmemcpy(buffer.name, printElement(student.name, width.name), 100);
  wmemcpy(buffer.surname, printElement(student.surname, width.name), 100);
  wmemcpy(buffer.patronymic, printElement(student.patronymic, width.name), 100);
  wmemcpy(buffer.group, printElement(student.group, width.group, true), 100);
  for (auto grade : student.grades)
    wcout << (grade != 0 ? static_cast<wchar_t>(grade + L'0') : L' ') << ' ';
  wcout << '|';
  printElement(student.yearOfBirth, width.birthYear);
  buffer.yearOfBirth = -1;
  if (wmemcmp(buffer.name, L"", 1) || wmemcmp(buffer.surname, L"", 1) || wmemcmp(buffer.patronymic, L"", 1) || wmemcmp(buffer.group, L"", 1))
    printOneStudent(-2, buffer, width);
};

void OutputToTheScreen(Student *students, int studentsAmount)
{
  const Widths width{3, 16, 10, 12, 5};
  printBorder(width.total);
  printTitle(width);
  printBorder(width.total);
  for (int i{}; i < studentsAmount; ++i)
    printOneStudent(i, students[i], width);
  printBorder(width.total);
  wcout << '\n';
}
