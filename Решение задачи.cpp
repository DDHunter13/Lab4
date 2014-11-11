#include <iostream>
#include <locale.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

struct Results {
	string FirstName;
	string SecName;
	double Score;
	bool operator<(const  Results& scr) {
		return (Score > scr.Score);
	}
};

int main(void) {

	setlocale(LC_ALL, "Russian");

	double sc1, sc2, sc3, max;
	int num, j;
	
	ifstream in("in.txt");
	if (!in.is_open()) {
		cout << "Файл не найден" << endl;
		return -1;
	}
	in >> num;
	Results *info = new Results[num];

	for (int i = 0; i < num; ++i) {
		in >> info[i].FirstName;
		in >> info[i].SecName;
		in >> sc1 >> sc2 >> sc3;
		max = fmax(sc1, sc2);
		max = fmax(max, sc3);
		info[i].Score = max;
	}
	sort(info, info + num);
	
	j = 0;
	for (int i = 0; i < 3; ++i) {
		if (j < num) {
			cout << info[j].FirstName << ' ' << info[j].SecName << ' ' << info[j].Score << '\n';
		}
		while ((j + 1 < num) && (info[j].Score == info[j + 1].Score)){
			cout << info[j + 1].FirstName << ' ' << info[j + 1].SecName << ' ' << info[j + 1].Score << '\n';
			++j;
		}
		++j;
	}

	delete[] info;
	return 0;
}
