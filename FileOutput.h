#pragma once

#include "Student.h"
#include <fstream>

void OutputToFile(const char *, Student *, int);
bool fileCheck(std::wofstream &f, const wchar_t *massage);
bool fileCheck(std::wifstream &f, const wchar_t *massage);