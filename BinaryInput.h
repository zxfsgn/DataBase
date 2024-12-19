#pragma once

#include "Student.h"

void ConvertTextToBin(const char* textName, const char* binName);
void GetFromBinary(const char* binName, Student* students, int& studentsAmount, int& currentId);