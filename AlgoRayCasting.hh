#ifndef	ALGO_RAYCASTING_HH_
#define ALGO_RAYCASTING_HH_

#include "IAlgo.hh"

class AlgoRayCasting : public IAlgo
{
	AlgoRayCasting(const AlgoRayCasting & rc) { }
	AlgoRayCasting & operator=(const AlgoRayCasting & rc) { return *this; }

	int calculLineHeight(const IWindow &window, const Scene &scene, int x) const;
public:
	AlgoRayCasting();
	virtual ~AlgoRayCasting();
	virtual void calcul(const IWindow &window, const Scene &scene) const;
};

#endif // ALGO_RAYCASTING_HH_