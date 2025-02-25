#pragma once
#include <string>

using std::string;

class Date
{
public:
  int date;
  int month;
  int year;

  // Date(int date, int month, int year);
  // Date getDate();
};

class Time
{
public:
  int hour;
  int minute;
  // Time(int hour, int minute);
  // Time getTime();
};
bool operator<(const Time &, const Time);

class Flight
{
public:
  unsigned number;
  Date date;
  Time time;
  string destination;
  string aircraft;
  unsigned seats;
  int intermediate;
};