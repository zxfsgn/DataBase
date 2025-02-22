#pragma once

struct Widths
{
  const int id;
  const int name;
  const int group;
  const int grades;
  const int birthYear;
  const int total = id + name * 3 + group + grades + birthYear + 8;
};
