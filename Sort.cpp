#include "Sort.h"
#include <iostream>
#include "Student.h"

using std::cin;
using std::cout;

void swap(Student[], int, int);
bool fieldCheck(int ,Student* , int , int );
void sort(Student*, int , int ,int ) ;

void sortShell(Student* students, int start, int end){
		cout<<"Enter column to sorting";
	int column;
	cin >> column;
	sort(students, start, end,column);
}

void sort(Student* students, int start, int end,int column) {

	if (start >= end)
		return;
	int  current{ start };
	for (int  i{ start + 1 }; i <= end; i++) {
		if (fieldCheck(column,students, start, i)) {
			swap(students, ++current, i);
		}
	}
	swap(students, start, current);
	sort(students, start, current - 1,column);
	sort(students, current + 1, end,column);
}

void swap(Student students[], int first, int second) {
	auto temp{ students[first] };
	students[first] = students[second];
	students[second] = temp;
}

bool fieldCheck(int column,Student* students, int k, int l){
	switch(column){
	case 1: return students[k].name < students[l].name; break;
	case 2: return students[k].surname < students[l].surname; break;
	case 3: return students[k].patronymic < students[l].patronymic; break;
	case 4: return students[k].group < students[l].group; break;
	case 5: return students[k].grades[0] < students[l].grades[0]; break;
	case 6: return students[k].yearOfBirth < students[l].yearOfBirth; break;
	} 
	return true;
}
