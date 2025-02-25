#include "InputChecks.h"
#include "Manipulations.h"

#include <iostream>
#include <limits>

using std::endl;
using std::wcerr;
using std::wcin;
using std::wcout;

int GetCorrectValue() // wchar_t *massage
{
  int n{};
  bool isNotOk{};
  do
  {
    isNotOk = false;
    if ((wcin >> n).fail())
    {
      FixStreamState();
      wcerr << L"Введён неверный символ" << endl;
      wcout << L"Введите целое число: " << endl;
      isNotOk = true;
    }
  } while (isNotOk);
  return n;
}

bool isNumInRange(int number, int leftBorder, int rightBorder)
{
  if (number >= leftBorder && number <= rightBorder)
    return true;
  return false;
}

int BirthCheck(int maxYear, int minYear)
{
  int year{};
  bool isNotOK{};
  do
  {
    isNotOK = false;
    year = GetCorrectValue();
    if (!isNumInRange(year, minYear, maxYear))
    {
      isNotOK = true;
      wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n');
      if (year < minYear)
      {
        wcerr << L"Слишком маленькое число. Введите другое\n";
      }
      else if (year > maxYear)
      {
        wcerr << L"Слишком большое число. Введите другое\n";
      }
    }
  } while (isNotOK);

  return year;
}

int GradeCheck(int gradeNumber)
{
  int grade{};
  bool isNotOk{};
  do
  {
    isNotOk = false;
    if ((wcin >> grade).fail() || grade < 1 || grade > 5)
    {
      FixStreamState();
      wcerr << L"Введено что-то неправильное" << endl;
      wcout << L"Введите ещё " << 6 - gradeNumber
            << L" целых " << (gradeNumber < 2 ? L"чисел" : L"числа")
            << L" от 1 до 5" << endl;
      isNotOk = true;
    }
  } while (isNotOk);
  return grade;
}

bool IndexCheck(int index, int studentsAmount)
{
  if (index < 1 || index > studentsAmount)
  {
    wcerr << L"Нет такого номера\n";
    return false;
  }
  return true;
}

bool isStringValid(wchar_t *str)
{
  /*int i = -1;
  while (str[++i] != '\0')
  {
    wchar_t ch = str[i];
    if ((ch < L'A' || ch > L'Z') && (ch < L'a' || ch > L'z') && (ch < L'а' || ch > L'я') && (ch < L'А' || ch > L'Я') && ch != L'-' && ch != L' ')
    {
      wcerr << L"Недопустимые символы\n";
      wcout << L"Попробуйте писать буквами" << endl;
      return false;
    }
  }*/
  return true;
}

bool areYouSure()
{
  bool answer;
  wcout << L"Вы уверены?\n1: да; 0: нет\n";
  wcin >> answer;
  return answer;
}