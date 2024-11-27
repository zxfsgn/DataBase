#include "Sort.h"
#include <iostream>
#include "Student.h"

void getArrFromStu(int(&arr)[], Student* students, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = students[i].yearOfBirth;
	}
}

void getSortedStu(Student* students, int(&arr)[], int size) {

}

void sort(int numbers[], size_t start, size_t end) {
	if (start >= end)
		return;
	size_t current{ start };
	for (size_t i{ start + 1 }; i <= end; i++) {
		if (numbers[i] < numbers[start]) {
			swap(numbers, ++current, i);
		}
	}
	swap(numbers, start, current);
	sort(numbers, start, current - 1);
	sort(numbers, current + 1, end);
}
void swap(int numbers[], size_t first, size_t second) {
	auto temp{ numbers[first] };
	numbers[first] = numbers[second];
	numbers[second] = temp;
}