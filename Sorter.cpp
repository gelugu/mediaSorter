#include "Sorter.h"

Sorter::Sorter()
{

}

Sorter::~Sorter()
{
}

void Sorter::search(const std::string& path)
{
	fs::recursive_directory_iterator it(path);
	fs::recursive_directory_iterator endit;
	while (it != endit)
	{
		if (fs::is_regular_file(*it)) {
			this->files.push_back(it->path().filename());
			this->extensions.insert(it->path().extension());
		}
		++it;
	}
}

bool Sorter::isPathCorrect(const std::string& path)
{
	return fs::is_directory(path);
}

void Sorter::createDirectory(const std::string& path)
{
	fs::create_directories(path);
}

void Sorter::sort()
{
}
