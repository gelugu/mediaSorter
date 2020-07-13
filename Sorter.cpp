#include "Sorter.h"

// debug
using namespace std;

Sorter::Sorter() {}

Sorter::~Sorter() {}

bool Sorter::isPathCorrect(const std::string& path) { return fs::is_directory(path); }

void Sorter::createDirectory(const std::string& path) { fs::create_directories(path); }

void Sorter::search(const std::string& path)
{
	fs::recursive_directory_iterator it(path);
	fs::recursive_directory_iterator endit;
	while (it != endit)
	{
		if (fs::is_regular_file(*it)) {
			this->files.push_back(it->path());
			this->extensionsPath.insert(make_pair(it->path().extension() == fs::path("") ? fs::path("none extenstoin") : it->path().extension(),	""));
		}
		++it;
	}
}

void Sorter::setup()
{
	system("cls");

	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	vector<COORD> pos;
	
	map<fs::path, fs::path>::iterator it{ this->extensionsPath.begin() };
	short i{ 0 };

	cout << "\n\tSetup folder stucture (\"-\" for ignore(delete):";
	
	for (; it != this->extensionsPath.end(); it++) {
		cout << "\n\t\t" << it->first << ": ";
		GetConsoleScreenBufferInfo(output, &cbsi);
		pos.push_back(cbsi.dwCursorPosition);
	}
	it = this->extensionsPath.begin();
	for (; it != this->extensionsPath.end(); it++, i++) {
		SetConsoleCursorPosition(output, pos[i]);
		cin >> it->second;
	}
	it = this->extensionsPath.begin();
	for (; it != this->extensionsPath.end(); it++) {
		if (it->second != fs::path("-"))
			cout << "\t" << it->first << " to " << it->second << endl;
	}
}

void Sorter::sort(const fs::path& path)
{
	fs::path newPath;
	for (auto e : this->files)
	{
		if (this->extensionsPath[e.extension()] == "-")	continue;
		newPath = path;
		newPath.append(this->extensionsPath[e.extension() == fs::path("") ? fs::path("none extenstoin") : e.extension()]);
		fs::create_directories(newPath); newPath.append(e.filename());

		fs::copy_file(e, newPath, fs::copy_options::overwrite_existing);
	}
}
