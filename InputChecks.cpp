#include "InputChecks.h"
#include <iostream>
#include "Manipulations.h"

using std::cin;
using std::cout;
using std::endl;

//bool isStudentsEmpty(Student* students, int& studentsAmount) {
//	if (studentsAmount > 0) {
//		DeleteAll(students, studentsAmount);
//		if (studentsAmount > 0) return false;
//	}
//	return true;
//}

int GetCorrectValue() {
	int n{};
	bool isNotOk{};

	do {
		isNotOk = false;
		if ((cin >> n).fail()) {
			FixStreamState();
			cout << "Illegal input!" << endl;
			cout << "Input command once more: " << endl;
			isNotOk = true;
		}
	} while (isNotOk);

	return n;
}

int BirthCheck(int maxYear, int minYear) {
	int year{};
	cin >> year;
	while (year<minYear or year>maxYear) {
		FixStreamState();
		if (year < minYear) {
			cout << "Year of birth is too small. Enter again\n";
		}
		else if (year > maxYear) {
			cout << "Year of birth is too big. Enter again\n";
		}
		cin >> year;
	}

	return year;
}

bool IndexCheck(int index, int studentsAmount) {
	if (index < 1 and index > studentsAmount) {
		cout << "Ќет студента с таким индексом\n";
		return false;
	}
	return true;
}

/*void StringCheck(){
	for (int i{}; i<lenght; ++i){
		if(word[i]==' '){
			cout<<"не должно содержать пробелов"
		}
	}
}//масштабировать колонку по размеру имени
проверка на вес символа дл€ кириллицы*/