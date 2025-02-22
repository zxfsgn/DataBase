#include <iostream>
#include <cmath>
#include "Student.h"
#include "Manipulations.h"
#include "OutputScreen.h"
#include "InputKeyboard.h"
#include "InputChecks.h"
#include "Request.h"
#include "Sort.h"
#include "FileOutput.h"
#include "FileInput.h"
#include "BinaryInput.h"

using std::endl;
using namespace std;

const char TFILE_NAME[] = "Students.txt";
const char BIN_NAME[] = "Students.bin";

int main()
{
  locale::global(locale("")); // set_locale

  int studentsAmount{};
  int currentId{};

  Student *students = new Student[100]{};
  size_t max_length{};

  int command{};

  do
  {
    PrintMenu();
    command = GetCorrectValue();
    switch (command)
    {
    case 1:
      InputFromKeyboard(students, studentsAmount, currentId);
      break;
    case 2:
      InputFromTFile(TFILE_NAME, students, studentsAmount, currentId);
      break;
    case 3:
      GetFromBinary(BIN_NAME, students, studentsAmount, currentId);
      break;
    case 4:
      OutputToTheScreen(students, studentsAmount);
      break;
    case 5:
      OutputToFile(TFILE_NAME, students, studentsAmount);
      break;
    case 6:
      request(students, studentsAmount);
      break;
    case 7:
      ConvertTextToBin(TFILE_NAME, BIN_NAME);
      break;
    case 8:
      createOne(students, studentsAmount, currentId);
      break;
    case 9:
      changeOne(students, studentsAmount);
      break;
    case 10:
      deleteOne(students, studentsAmount);
      break;
    case 11:
      sortShell(students, 0, studentsAmount - 1);
      break;
    case 0:
      wcout << L"Всего хорошего!\n"
            << endl;
      break;
    default:
      wcout << L"Неправильно! Попробуйте ещё раз\n";
    }

  } while (command);
}

void PrintMenu()
{
  // cycle of consts
  wcout << L"1 - ввести с клавиатуры" << endl;
  wcout << L"2 - ввести из файла" << endl;
  wcout << L"3 - ввести из бинарного файла" << endl;
  wcout << L"4 - вывести на экран" << endl;
  wcout << L"5 - вывести в файл" << endl;
  wcout << L"6 - показать фамилии и группы студентов, получивших не более двух 4 (остальные оценки - 5) " << endl;
  wcout << L"7 - перевести из текстового файла в бинарный" << endl;
  wcout << L"8 - добавить студента" << endl;
  wcout << L"9 - изменить студента" << endl;
  wcout << L"10- удалить студента" << endl;
  wcout << L"11- сортировать" << endl;
  wcout << L"0 - выйти" << endl;
}
