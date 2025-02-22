#include "Request.h"
#include <iostream>

using std::wcout;

void request(Student *students, const int studentsAmount)
{
  bool isExists = false;
  for (int i = 0; i < studentsAmount; ++i)
  {
    bool fl = true;
    int fourCounter = 0;
    for (auto grade : students[i].grades)
    {
      if (grade < 4 or grade == 4 and ++fourCounter > 2)
      {
        fl = false;
        break;
      }
    }
    if (fl)
    {
      isExists = true;
      wcout << students[i].surname << L" из группы " << students[i].group << '\n';
    }
  }
  if (!isExists)
    wcout << L"Таких здесь нет!\n";
  wcout << std::endl;
}