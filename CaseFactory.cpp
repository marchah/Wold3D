#include <string>

#include "CaseFactory.hh"
#include "BlockWall.hh"
#include "BlockEmpty.hh"
#include "PlayerBasic.hh"

ptr_func	table[] =
{
	{ICase::EMPTY, '0', &CaseFactory::createBlockEmpty},
	{ICase::WALL, '1', &CaseFactory::createBlockWall},
	{ICase::WALL, '2', &CaseFactory::createBlockWall},
	{ICase::WALL, '3', &CaseFactory::createBlockWall},
	{ICase::WALL, '4', &CaseFactory::createBlockWall},
	{ICase::WALL, '5', &CaseFactory::createBlockWall},
	{ICase::WALL, '6', &CaseFactory::createBlockWall},
	{ICase::WALL, '7', &CaseFactory::createBlockWall},
	{ICase::WALL, '8', &CaseFactory::createBlockWall},
	{ICase::WALL, '9', &CaseFactory::createBlockWall},
	{ICase::PLAYER_BASIC, 'P', &CaseFactory::createPlayerBasic},
	{ICase::EMPTY, '\0', NULL}
};

ICase *CaseFactory::createCase(const char c)
{
	for (int i = 0; table[i].c != '\0'; i++)
	{
		if (table[i].c == c)
			return ((*table[i].ptr)());
	}
	throw CaseFactoryException("Unknow typeBlock.");
	return (NULL);
}

ICase *CaseFactory::createCase(ICase::eTypeCase type)
{
	for (int i = 0; table[i].c != '\0'; i++)
	{
		if (table[i].type == type)
			return ((*table[i].ptr)());
	}
	throw CaseFactoryException("Unknow typeBlock.");
	return (NULL);
}

ICase *CaseFactory::createBlockEmpty()
{
	return (new BlockEmpty());
}

ICase *CaseFactory::createBlockWall()
{
	return (new BlockWall());
}

ICase *CaseFactory::createPlayerBasic()
{
	return (new PlayerBasic());
}

