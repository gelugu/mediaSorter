#include <iostream>
#include <vector>
#include <set>
#include <Windows.h>

#include "Sorter.h"

namespace fs = std::experimental::filesystem;
using namespace std;

int main()
{
	// init paths
	string searchPath;
	string sortPath;

	// input paths
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		system("cls");
		cout << "\n\tChoose folder: "; //cin >> searchPath;
		getline(cin, searchPath);
	} while (!Sorter::isPathCorrect(searchPath));
	do {
		system("cls");
		cout << "\n\tChoose save folder: "; cin >> sortPath;

		if (!Sorter::isPathCorrect(sortPath.substr(0, 2))) {
			cout << "Local disk " << sortPath.substr(0, 2) << "don't exist." << endl;
			system("pause");
			continue;
		}
		Sorter::createDirectory(sortPath);
	} while (!Sorter::isPathCorrect(sortPath));
	
	Sorter sort;
	sort.search(searchPath);
	sort.setup();

	// start first thread
	//sorter.search(searchPath);
	// end first thread
	/*
	cout << "Find _N_ files...\n\t_M_ images\n\t_Z_ audio\n";
	
	//_wmkdir((wchar_t*)"_sortPath");
	cout << "Making output directory...\n";

	cout << "Sorting files...\n";
	// start second thread
	sorter.sort();
	// end second thread

	cout << "Done!\n\t_N_ files have been sorted in _A_ directoris\n\t_B_ files have been deleted (as copyies).\n\n";
	*/
}