#include "PlayerBasic.hh"

PlayerBasic::PlayerBasic()
: APlayer(ICase::PLAYER_BASIC, 60, 32, 0.0, 0.66, POV(0,0,-1,0))
{

}

PlayerBasic::~PlayerBasic()
{

}

double PlayerBasic::getMoveSpeed(float deltaTimeSecond) const
{
    return deltaTimeSecond * 300.0; //the constant value is in squares/second
}

double PlayerBasic::getRotationSpeed(float deltaTimeSecond) const
{
    return deltaTimeSecond * 200.0; //the constant value is in radians/second
}

void PlayerBasic::moveUp(const Map &map, float deltaTimeSecond)
{
	double moveSpeed = this->getMoveSpeed(deltaTimeSecond);
	if (map.getTypeCaseAt((int)(this->pov_.x + this->pov_.dirX * moveSpeed), (int)this->pov_.y) != ICase::WALL)
		this->pov_.x += this->pov_.dirX * moveSpeed;
	if (map.getTypeCaseAt((int)this->pov_.x, (int)(this->pov_.y + this->pov_.dirY * moveSpeed)) != ICase::WALL)
		this->pov_.y += this->pov_.dirY * moveSpeed;
}

void PlayerBasic::moveDown(const Map &map, float deltaTimeSecond)
{
	double moveSpeed = this->getMoveSpeed(deltaTimeSecond);
	if(map.getTypeCaseAt((int)(this->pov_.x - this->pov_.dirX * moveSpeed), (int)this->pov_.y) != ICase::WALL)
		this->pov_.x -= this->pov_.dirX * moveSpeed;
	if(map.getTypeCaseAt((int)this->pov_.x, (int)(this->pov_.y - this->pov_.dirY * moveSpeed)) != ICase::WALL)
		this->pov_.y -= this->pov_.dirY * moveSpeed;
}

void PlayerBasic::moveRight(const Map &map, float deltaTimeSecond)
{
	double rotSpeed = this->getRotationSpeed(deltaTimeSecond);
	//both camera direction and camera plane must be rotated
	double oldDirX = this->pov_.dirX;
	this->pov_.dirX = this->pov_.dirX * cos(-rotSpeed) - this->pov_.dirY * sin(-rotSpeed);
	this->pov_.dirY = oldDirX * sin(-rotSpeed) + this->pov_.dirY * cos(-rotSpeed);
	double oldPlaneX = this->planeX_;
	this->planeX_ = this->planeX_ * cos(-rotSpeed) - this->planeY_ * sin(-rotSpeed);
	this->planeY_ = oldPlaneX * sin(-rotSpeed) + this->planeY_ * cos(-rotSpeed);
}

void PlayerBasic::moveLeft(const Map &map, float deltaTimeSecond)
{
	double rotSpeed = this->getRotationSpeed(deltaTimeSecond);
	//both camera direction and camera plane must be rotated
	double oldDirX = this->pov_.dirX;
	this->pov_.dirX = this->pov_.dirX * cos(rotSpeed) - this->pov_.dirY * sin(rotSpeed);
	this->pov_.dirY = oldDirX * sin(rotSpeed) + this->pov_.dirY * cos(rotSpeed);
	double oldPlaneX = this->planeX_;
	this->planeX_ = this->planeX_ * cos(rotSpeed) - this->planeY_ * sin(rotSpeed);
	this->planeY_ = oldPlaneX * sin(rotSpeed) + this->planeY_ * cos(rotSpeed);
}
