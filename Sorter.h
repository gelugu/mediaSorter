#pragma once

#include <string>
#include <vector>
#include <set>

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class Sorter
{
public:
	Sorter();
	~Sorter();

	void search(const std::string& path);
	void setup();
	static bool isPathCorrect(const std::string& path);
	static void createDirectory(const std::string& path);
	void sort();	//second thread sorting (also searching copies) when files attemped
		/*
			sort dir:
				-year
					-img
						-devies1
							-month1
							-month2
						-devies2
							-...
					-video
						-devies1
							-month1
							-month2
						-devies2
							-...
					-audio
						-.mp3
						-.waw
		*/

private:
	vector<fs::path> files;
	set<fs::path> extensions;
};