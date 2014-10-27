#include <iostream>
#include <locale.h>
#include <fstream>
#include <stdio.h>

using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");

	ifstream in("in.txt");
	if (!in.is_open()) {
		cout << "Файл не найден" << endl;
		return -1;
	}

	char space[] = " ";
	char readstr[50];
	int score[100];
	char names[100][50];
	int i, n, j;
	int sc1 = 0;
	int sc2 = 0;
	int sc3 = 0;

	n = 0;
	for (i = 0; i < 100; ++i) {
		in.getline(names[n], 49);
		
		if (in.fail()) {
			break;
		}
		
		strncat_s(names[n], space, 2);
		
		
		for (i = 0; names[n][i] != ' '; ++i);
		++i;
		for (i; names[n][i] != ' '; ++i);
		++i;
		sc1 = 0;
		sc2 = 0;
		sc3 = 0;
		for (i; names[n][i] != ' '; ++i) {
			sc1 = ((int)(names[n][i]) - (int)('1') + 1) + sc1 * 10;
		}
		++i;
		for (i; names[n][i] != ' '; ++i) {
			sc2 = ((int)(names[n][i]) - (int)('1') + 1) + sc2 * 10;
		}
		++i;
		for (i; names[n][i] != ' '; ++i) {
			sc3 = ((int)(names[n][i]) - (int)('1') + 1) + sc3 * 10;
		}
		++i;

		if (sc1 < sc2) {
			sc1 = sc2;
		}
		if (sc1 < sc3) {
			sc1 = sc3;
		}
		score[n] = sc1;
		++n;
		
	}

	for (i = 0; i < n; ++i) {
		for (j = i + 1; j < n; ++j) {
			if (score[i] < score[j]) {
				swap(names[i], names[j]);
				swap(score[i], score[j]);
			}
		}
	}
	j = 0;
	for (i = 0; i < 3; ++i) {
		cout << names[j] << endl;
		while (score[j] == score[j + 1]) {
			cout << names[j + 1] << endl;
			++j;
		}
		++j;
	}

	return 0;
}
