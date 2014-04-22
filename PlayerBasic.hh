#ifndef	PLAYER_BASIC_HH_
#define PLAYER_BASIC_HH_

#include "APlayer.hh"


class	PlayerBasic : public APlayer
{
public:
	PlayerBasic();
	PlayerBasic(const PlayerBasic & p) : APlayer(p.getTypeCase(), p.fov_, p.height_, p.planeX_, p.planeY_, p.pov_) { }
	virtual ~PlayerBasic();
	virtual PlayerBasic & operator=(const PlayerBasic & p) { this->typeCase_ = p.getTypeCase(); this->fov_ = p.fov_, this->height_ = p.height_; this->planeX_ = p.planeX_; this->planeY_ = p.planeY_; this->pov_ = p.pov_; return *this; }

	virtual void		moveUp(const Map &map, float deltaTimeSecond);
	virtual void		moveDown(const Map &map, float deltaTimeSecond);
	virtual void		moveRight(const Map &map, float deltaTimeSecond);
	virtual void		moveLeft(const Map &map, float deltaTimeSecond);
private:
	double	getMoveSpeed(float deltaTimeSecond) const;
	double	getRotationSpeed(float deltaTimeSecond) const;
};

#endif // PLAYER_BASIC_HH_