#ifndef	BLOCK_WALL_HH_
#define BLOCK_WALL_HH_

#include "ABlock.hh"

class BlockWall : public ABlock
{
public:
	BlockWall();
	virtual ~BlockWall();

	BlockWall(const BlockWall & bw) : ABlock(bw.getTypeCase()) { }
	BlockWall & operator=(const ABlock & bw) { this->typeCase_ = bw.getTypeCase(); return *this; }
};

#endif // BLOCK_WALL_HH_