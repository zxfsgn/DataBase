#include "Sort.h"
#include <iostream>
#include "Student.h"

void swap(Student[], size_t, size_t);

void sort(Student students[], size_t start, size_t end) {
	if (start >= end)
		return;
	size_t current{ start };
	for (size_t i{ start + 1 }; i <= end; i++) {
		if (students[i].yearOfBirth < students[start].yearOfBirth) {
			swap(students, ++current, i);
		}
	}
	swap(students, start, current);
	sort(students, start, current - 1);
	sort(students, current + 1, end);
}
void swap(Student students[], size_t first, size_t second) {
	auto temp{ students[first] };
	students[first] = students[second];
	students[second] = temp;
}