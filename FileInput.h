#pragma once

#include "Student.h"

#include <fstream>

bool InitializeStudentFromText(std::wifstream &f, Student &student);
void InputFromTFile(const char *, Student *, int &, int &);
