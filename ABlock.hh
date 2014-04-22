#ifndef	ABLOCK_HH_
#define ABLOCK_HH_

#include "ACase.hh"

class	ABlock : public ACase
{
public:
	const static int sizeBlock = 64;

			ABlock(eTypeCase typeCase) : ACase(typeCase) {}
	virtual ~ABlock()	{}
	virtual ABlock & operator=(const ABlock & b) { this->typeCase_ = b.getTypeCase(); return *this; }
	virtual bool	isPlayer() const { return false; }
};

#endif // ABLOCK_HH_