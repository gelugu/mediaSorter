#pragma once

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>

// debug
#include <iostream>
#include <Windows.h>

#include <string>
#include <vector>
#include <set>
#include <map>

namespace fs = std::experimental::filesystem;

class Sorter
{
public:
	Sorter();
	~Sorter();

	static bool isPathCorrect(const std::string& path);
	static void createDirectory(const std::string& path);

	void search(const std::string& path);
	void setup();
	void sort(const fs::path& path);	//second thread sorting (also searching copies) when files attemped
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
	std::vector<fs::path> files;
	std::map<fs::path, fs::path> extensionsPath;
};