#ifndef	APLAYER_HH_
#define APLAYER_HH_

#include "ACase.hh"
#include "Map.hh"
#include <vector>

class	APlayer : public ACase
{
public:
	typedef struct s_pov
	{
		double x;
		double y;
		double dirX;
		double dirY;
		s_pov() {}
		s_pov(double x, double y, double dirX, double dirY) { this->x = x; this->y = y; this->dirX = dirX; this->dirY = dirY; }
		s_pov(const s_pov & c) { this->x = c.x; this->y = c.y; this->dirX = c.dirX; this->dirY = c.dirY; }
		s_pov & operator=(const s_pov & c) { this->x = c.x; this->y = c.y; this->dirX = c.dirX; this->dirY = c.dirY; return *this; }
	} POV;
protected:
	int		fov_;
	int		height_;
	float	planeX_;
	float	planeY_;
	POV		pov_;
public:

	APlayer(ICase::eTypeCase typeCase, int fov, int height, float planeX, float planeY, POV coord) : ACase(typeCase), fov_(fov), height_(height), planeX_(planeX), planeY_(planeY) { this->pov_ = coord; }
	virtual ~APlayer()	{}
	virtual APlayer & operator=(const APlayer & p) { this->typeCase_ = p.getTypeCase(); this->fov_ = p.fov_, this->height_ = p.height_; this->planeX_ = p.planeX_; this->planeY_ = p.planeY_; this->pov_ = p.pov_; return *this; }
	virtual bool		isPlayer() const	{ return true; }
	POV					getPOV() const		{ return this->pov_; }
	void				setPOV(POV pov)		{ this->pov_ = pov; }
	int					getFOV() const		{ return this->fov_; }
	float				getPlaneX() const	{ return this->planeX_; }
	float				getPlaneY() const	{ return this->planeY_; }
	void				setPlaneX(float planeX) {this->planeX_ = planeX;}
	void				setPlaneY(float planeY) {this->planeY_ = planeY;}
	virtual void		moveUp(const Map &map, float deltaTimeSecond) = 0;
	virtual void		moveDown(const Map &map, float deltaTimeSecond) = 0;
	virtual void		moveRight(const Map &map, float deltaTimeSecond) = 0;
	virtual void		moveLeft(const Map &map, float deltaTimeSecond) = 0;
};

#endif // APLAYER_HH_