#include "Sorter.h"

Sorter::Sorter()
{

}

Sorter::~Sorter()
{
}

void Sorter::search(const std::string& path)
{
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
