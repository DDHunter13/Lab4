#include <iostream>
#include <locale.h>
#include <fstream>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");

	char str[20];
	char str2[6];
	char place1[40];
	char place2[40];
	char place3[40];
	char space[] = " ";
	int b1, b2, b3, max1, max2, max3;
	int i, g;

	ifstream in("in.txt");
	if (!in.is_open()) {
		cout << "Файл не найден" << endl;
		return -1;
	}
	max1 = 0;
	max2 = 0;
	max3 = 0;
	
	in >> g;
	for (i = 0; i < g; ++i) {
		in.getline(str, 19, ' ');
		if (in.fail()) {
			cout << "Ошибка чтения файла" << endl;
			return -2;
		}
		in.getline(str2, 5, ' ');
		if (in.fail()) {
			cout << "Ошибка чтения файла" << endl;
			return -3;
		}
		in >> b1 >> b2 >> b3;
		if (in.fail()) {
			cout << "Ошибка чтения файла" << endl;
			return -4;
		};
		if (b3 > b2) {
			swap(b2, b3);
		}
		if (b2 > b1) {
			swap(b1, b2);
		}
		if (b1 >= max1) {
			max3 = max2;
			max2 = max1;
			max1 = b1;

			strncpy_s(place3, place2, 39);
			strncpy_s(place2, place1, 39);

			strncpy_s(place1, str, 29);
			strncat_s(place1, space, 1);
			strncat_s(place1, str2, 5);
		}
		else if (b1 >= max2) {
			max3 = max2;
			max2 = b1;

			strncpy_s(place3, place2, 39);

			strncpy_s(place2, str, 29);
			strncat_s(place2, space, 1);
			strncat_s(place2, str2, 5);
		}
		else if (b1 >= max3) {
			max3 = b1;

			strncpy_s(place3, str, 29);
			strncat_s(place3, space, 1);
			strncat_s(place3, str2, 5);
		}
	}
	cout << place1 << endl;
	cout << place2 << endl;
	cout << place3 << endl;
	return 0;
}
