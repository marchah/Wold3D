#include "AlgoRayCasting.hh"

AlgoRayCasting::AlgoRayCasting()
{

}

AlgoRayCasting::~AlgoRayCasting()
{
}

int		AlgoRayCasting::calculLineHeight(const IWindow &window, const Scene &scene, int x) const
{
	
	//calculate ray position and direction
	// getWidth() ou getHeight() ??????
	double cameraX = 2 * x / double(window.getWidth()) - 1; //x-coordinate in camera space
	double rayPosX = scene.getPlayer()->getPOV().x;
	double rayPosY = scene.getPlayer()->getPOV().y;
	double rayDirX = scene.getPlayer()->getPOV().dirX + scene.getPlayer()->getPlaneX() * cameraX;
	double rayDirY = scene.getPlayer()->getPOV().dirY + scene.getPlayer()->getPlaneY() * cameraX;

	//which box of the map we're in
	int mapX = int(rayPosX);
	int mapY = int(rayPosY);

	//length of ray from current position to next x or y-side
	double sideDistX;
	double sideDistY;

	//length of ray from one x or y-side to next x or y-side
	double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
	double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
	double perpWallDist;

	//what direction to step in x or y-direction (either +1 or -1)
	int stepX;
	int stepY;

	int hit = 0; //was there a wall hit?
	int side; //was a NS or a EW wall hit?

	//calculate step and initial sideDist
	if (rayDirX < 0)
	{
		stepX = -1;
		sideDistX = (rayPosX - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
		sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
	}
	if (rayDirY < 0)
	{
		stepY = -1;
		sideDistY = (rayPosY - mapY) * deltaDistY;
	}
	else
	{
		stepY = 1;
		sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
	}
	//perform DDA
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (sideDistX < sideDistY)
		{
			sideDistX += deltaDistX;
			mapX += stepX;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		//Check if ray has hit a wall
		if (scene.getMap()->getTypeCaseAt(mapX, mapY) == ICase::WALL)
			hit = 1;
	}

	//Calculate distance of perpendicular ray (oblique distance will give fisheye effect!)
	if (side == 0)
		perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
	else
		perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);

	//Calculate height of line to draw on screen
	return abs(int(window.getHeight() / perpWallDist));
}

#include <iostream>

void	AlgoRayCasting::calcul(const IWindow &window, const Scene &scene) const
{
	// avant c'était getWidth(), deja changer, voir pour changer partout car se con à tout inversé on dirait
    for(int x = 0; x < window.getHeight(); x++)
    {

		int lineHeight = this->calculLineHeight(window, scene, x);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + window.getWidth() / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + window.getWidth() / 2;
		if(drawEnd >= window.getWidth())
			drawEnd = window.getWidth() - 1;


		IWindow::Color color;

		color.red = 0;
		color.green = 0;
		color.blue = 255;

		window.drawLine((float)x, drawStart, drawEnd, color);
	}
}