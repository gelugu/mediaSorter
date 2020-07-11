#include <iostream>
#include "Sorter.h"

using namespace std;



int main()
{
	// init variables
	Sorter sorter;

	// init paths
	string searchPath{ "" };
	string sortPath{ "" };

	// input paths
	cout << "Choose folder: "; cin >> searchPath;
	cout << "Choose save folder: "; cin >> sortPath;

	// recursive search in derectory for all files
	cout << "Search in \'" << searchPath << "\'...\n";
	// start first thread
	// pushing files into Files(class)
	sorter.push(searchPath);
	// end first thread

	cout << "Find _N_ files...\n\t_M_ images\n\t_Z_ audio\n";
	
	_wmkdir((wchar_t*)"_sortPath");
	cout << "Making output directory...\n";

	cout << "Sorting files...\n";
	// start second thread
	sorter.sort();
	// end second thread

	cout << "Done!\n\t_N_ files have been sorted in _A_ directoris\n\t_B_ files have been deleted (as copyies).\n\n";

}