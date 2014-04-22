#ifndef	BLOCK_EMPTY_HH_
#define BLOCK_EMPTY_HH_

#include "ABlock.hh"

class BlockEmpty : public ABlock
{
public:
	BlockEmpty();
	virtual ~BlockEmpty();

	BlockEmpty(const BlockEmpty & be) : ABlock(be.getTypeCase()) { }
	BlockEmpty & operator=(const ABlock & be) { this->typeCase_ = be.getTypeCase(); return *this; }
};

#endif // BLOCK_EMPTY_HH_