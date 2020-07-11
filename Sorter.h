#pragma once

#include <string>
#include <vector>

class Sorter
{
public:
	Sorter();
	~Sorter();

	void push(std::string path);
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
	std::vector<std::string> paths{};
};