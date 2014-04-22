#ifndef	MAP_HH_
#define MAP_HH_

#include <vector>

#include "ICase.hh"

class	Map
{
	std::vector<std::vector<ICase*>*> *map_;

	Map & operator=(const Map & m) { return *this; }
	Map(const Map & m) {}
public:
	Map();
	~Map();
	void				addCase(ICase *c);
	void				addLine();
	void				displayMapOnConsole() const;
	ICase::eTypeCase	getTypeCaseAt(int y, int x) const;
};

#endif // MAP_HH_