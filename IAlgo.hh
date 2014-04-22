#ifndef	IALGO_HH_
#define IALGO_HH_

#include "IWindow.hh"

#include <vector>

class	IAlgo
{
public:
	virtual ~IAlgo() {}
	virtual void calcul(const IWindow &window, const Scene &scene) const = 0;
};

#endif // IALGO_HH_