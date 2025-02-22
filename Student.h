#pragma once
#include "Widths.h"

struct Student
{
  int id;
  wchar_t name[100];
  wchar_t surname[100];
  wchar_t patronymic[100];
  int yearOfBirth;
  wchar_t group[100];
  int grades[6];
};