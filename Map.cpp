#include <string>

#include "Map.hh"

#include <iostream>

Map::Map()
{
	this->map_ = new std::vector<std::vector<ICase*>*>();
}

Map::~Map()
{
	for (std::vector<std::vector<ICase*>*>::iterator it = this->map_->begin(); it != this->map_->end(); ++it)
	{
		for (std::vector<ICase*>::iterator it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
			delete *it2;
		delete *it;
	}
	delete this->map_;
}

void	Map::addCase(ICase *c)
{
	this->map_->back()->push_back(c);
}
	
void	Map::addLine()
{
	this->map_->push_back(new std::vector<ICase*>());
}

void	Map::displayMapOnConsole() const
{
	for (std::vector<std::vector<ICase*>*>::iterator it = this->map_->begin(); it != this->map_->end(); ++it)
	{
		for (std::vector<ICase*>::iterator it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
		{
			std::cout << (int)(*it2)->getTypeCase();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

ICase::eTypeCase	Map::getTypeCaseAt(int y, int x) const
{
	return this->map_->at(y)->at(x)->getTypeCase();
}