#include "Student.h"
#include "FileInput.h"
#include "FileOutput.h"
#include "Manipulations.h"

#include <fstream>
#include <iostream>

using namespace std;

bool fileCheck(ofstream &f, const wchar_t *massage)
{
  if (!f)
  {
    wcerr << massage;
    return false;
  }
  return true;
}

bool fileCheck(ifstream &f, const wchar_t *massage)
{
  if (!f)
  {
    wcerr << massage;
    return false;
  }
  return true;
}

void ConvertTextToBin(const char *textName, const char *binName)
{
  ofstream fout(binName, ios::binary);
  wifstream fin(textName);
  if (!fileCheck(fout, L"Бинарный файл не может быть создан\n"))
    return;
  if (!fileCheck(fin, L"Текстовый файл не может быть открыт\n"))
    return;
  Student buf{};
  while (InitializeStudentFromText(fin, buf))
    fout.write(reinterpret_cast<char *>(&buf) + 4, sizeof(buf) - 4);
  fin.close();
  fout.close();
}

void GetFromBinary(const char *binName, Student *students, int &studentsAmount, int &currentId)
{
  ifstream fin(binName, ios::binary);
  if (!fileCheck(fin, L"Файл не может быть открыт\n"))
    return;
  Student buf{};
  DeleteAll(students, studentsAmount);
  while (fin.read(reinterpret_cast<char *>(&buf) + 4, sizeof(buf) - 4))
  {
    buf.id = currentId++;
    students[studentsAmount++] = buf;
  }
  fin.close();
}