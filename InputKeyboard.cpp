#include "InputKeyboard.h"
#include "Manipulations.h"

#include <iostream>

using std::endl;
using std::wcin;
using std::wcout;

void InputFromKeyboard(Student *students, int &studentsAmount, int &currentId)
{
  DeleteAll(students, studentsAmount);
  while (true)
  {
    createOne(students, studentsAmount, currentId);
    wcout << L"Закончить с ними?(да - 1, нет - 0) ";
    int answer;
    wcin >> answer;
    if (answer == 1)
      break;
  }
}